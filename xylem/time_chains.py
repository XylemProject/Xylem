"""Time a run-file chain across Python, Rust, C, and mixed backends.

Two timing paths are reported:

- wrapper: goes through call_c/call_rust each step. Those helpers re-read and
  hash or parse the source file on every call (load_c's cache key includes
  _source_digest; load_rust calls _abi_kind -> _source_text). Compile is
  cached, but the per-call file I/O dominates.
- raw: pre-resolves the ctypes function handle after warmup, then encodes
  args and calls the raw function, the same approach as time_c/time_rust.
  $prev still has to be encoded each step because it changes.

Compile and library lookup happen during warmup and are not included in the
timed loop. A top-level "mixed" list selects the mixed-language variant.
This is a bench helper, not part of a content hash.
"""

from __future__ import annotations

import json
import os
import statistics
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MSYS_BIN = r"C:\msys64\ucrt64\bin"


def _p(*args, **kwargs):
    kwargs.setdefault("flush", True)
    print(*args, **kwargs)


def _prepare_path():
    path = os.environ.get("PATH", "")
    if os.path.isdir(MSYS_BIN) and MSYS_BIN not in path.split(os.pathsep):
        os.environ["PATH"] = MSYS_BIN + os.pathsep + path


def _entry_language(entry) -> str:
    return str(entry.get("language") or "python").lower()


def _resolve_source(entry) -> str:
    source = entry.get("source_file") or ""
    path = Path(source)
    if not path.is_file():
        path = ROOT / source
    if not path.is_file():
        raise FileNotFoundError(f"Source file not found: {source}")
    return str(path.resolve())


def _pick_backend(job: str, language: str):
    from xylem.hasher.library import find_backends

    wanted = language.lower()
    matches = [item for item in find_backends(job) if _entry_language(item) == wanted]
    if not matches:
        raise RuntimeError(f"No {language} backend for {job}")
    for status in ("verified_basic", "verified_external"):
        for item in matches:
            if item.get("status") == status:
                return item
    return matches[0]


def _values_equal(left, right) -> bool:
    from xylem.hasher.c_caller import c_values_equal

    return c_values_equal(left, right)


def _make_wrapper_caller(entry, arg_count: int):
    """Stock path: call_c/call_rust (re-reads source) or a loaded Python fn."""
    from xylem.cli import load_entry_function
    from xylem.hasher.c_caller import call_c, load_c
    from xylem.hasher.rust_caller import call_rust, load_rust

    language = _entry_language(entry)
    source = _resolve_source(entry)
    function_name = entry.get("function_name") or ""
    if language == "c":
        load_c(source, function_name, arg_count)

        def call(args, _source=source, _name=function_name):
            return call_c(_source, _name, args)

        return call
    if language == "rust":
        load_rust(source, function_name, arg_count)

        def call(args, _source=source, _name=function_name):
            return call_rust(_source, _name, args)

        return call
    fn = load_entry_function({"source_file": source, "function_name": function_name})

    def call(args, _fn=fn):
        return _fn(*args)

    return call


def _make_raw_caller(entry, arg_count: int):
    """Pre-resolved ctypes handle, same idea as time_c/time_rust."""
    from xylem.cli import load_entry_function
    from xylem.hasher import c_caller
    from xylem.hasher import rust_caller

    language = _entry_language(entry)
    source = _resolve_source(entry)
    function_name = entry.get("function_name") or ""
    if language == "c":
        c_caller.load_c(source, function_name, arg_count)
        raw_fn = ret_kind = arg_kinds = None
        abspath = os.path.abspath(source)
        for key, value in c_caller._loaded.items():
            if key[0] == abspath and key[1] == function_name and key[2] == arg_count:
                _wrapper, raw_fn, ret_kind, arg_kinds = value
                break
        if raw_fn is None:
            raise RuntimeError(f"C raw handle missing for {function_name}")

        def call(args, _fn=raw_fn, _ret=ret_kind, _kinds=arg_kinds):
            encoded = [c_caller._encode_arg(item, kind) for item, kind in zip(args, _kinds)]
            return c_caller._decode_result(_fn(*encoded), _ret)

        return call
    if language == "rust":
        raw_fn, kind = rust_caller.load_rust(source, function_name, arg_count)

        def call(args, _fn=raw_fn, _kind=kind):
            encoded = [rust_caller._encode_arg(item, _kind) for item in args]
            return rust_caller._decode_result(_fn(*encoded), _kind)

        return call
    fn = load_entry_function({"source_file": source, "function_name": function_name})

    def call(args, _fn=fn):
        return _fn(*args)

    return call


def _languages_for(spec: dict, variant: str, steps: list) -> list:
    if variant == "python":
        return ["python"] * len(steps)
    if variant == "rust":
        return ["rust"] * len(steps)
    if variant == "c":
        return ["c"] * len(steps)
    if variant == "mixed":
        mixed = spec.get("mixed")
        if not mixed or len(mixed) != len(steps):
            raise RuntimeError("mixed variant needs a mixed list with one language per step")
        return [str(item).lower() for item in mixed]
    raise RuntimeError(f"unknown variant {variant}")


def _prepare(spec: dict, variant: str, path_kind: str):
    steps = spec.get("steps") or []
    if not steps:
        raise RuntimeError("chain has no steps")
    languages = _languages_for(spec, variant, steps)
    maker = _make_raw_caller if path_kind == "raw" else _make_wrapper_caller
    prepared = []
    for step, language in zip(steps, languages):
        entry = _pick_backend(step.get("name"), language)
        caller = maker(entry, len(step.get("args") or []))
        prepared.append((step, language, entry, caller))
    return prepared


def _run(prepared):
    previous = None
    started = False
    for step, _language, _entry, caller in prepared:
        args = []
        for item in step.get("args") or []:
            if item == "$prev":
                if not started:
                    raise RuntimeError(f"$prev used before any result at {step.get('name')}")
                args.append(previous)
            else:
                args.append(item)
        previous = caller(args)
        started = True
    return previous


def _calibrate(prepared, target_seconds: float, lo: int, hi: int) -> int:
    probe = min(200, hi)
    started = time.perf_counter()
    for _ in range(probe):
        _run(prepared)
    elapsed = time.perf_counter() - started
    if elapsed <= 0:
        return lo
    loops = int(probe * (target_seconds / elapsed))
    return max(lo, min(loops, hi))


def _time_variant(label, prepared, python_final, steps, loops, runs):
    samples = []
    _run(prepared)
    for run_number in range(1, runs + 1):
        started = time.perf_counter()
        last = None
        for _ in range(loops):
            last = _run(prepared)
        elapsed = time.perf_counter() - started
        if not _values_equal(last, python_final):
            raise RuntimeError(f"VERIFY FAIL during {label} run {run_number}: {last!r}")
        us_chain = (elapsed / loops) * 1_000_000
        us_step = us_chain / max(len(steps), 1)
        samples.append(us_chain)
        _p(
            f"  {label:15s} run {run_number}: {elapsed:.4f}s  "
            f"{us_chain:.3f} us/chain  {us_step:.3f} us/step"
        )
    return samples


def _summarize(path_name, variants, results, steps):
    _p(f"Summary {path_name} (median us/chain, us/step):")
    for variant in variants:
        samples = results[variant]
        median = statistics.median(samples)
        mean = statistics.mean(samples)
        lo, hi = min(samples), max(samples)
        us_step = median / max(len(steps), 1)
        raw = [f"{item:.3f}" for item in samples]
        _p(
            f"  {variant:7s}  median={median:.3f}  mean={mean:.3f}  "
            f"min={lo:.3f}  max={hi:.3f}  us/step={us_step:.3f}  raw={raw}"
        )


def time_chain(path: str, raw_runs: int = 5, wrapper_runs: int = 3):
    path = str(Path(path))
    with open(path, "r", encoding="utf-8") as handle:
        spec = json.load(handle)
    steps = spec.get("steps") or []
    variants = ["python", "rust", "c", "mixed"]
    _p(f"Chain: {spec.get('name') or path}")
    _p(f"File:  {path}")
    _p(f"Steps: {len(steps)}")
    if spec.get("description"):
        _p(spec["description"])

    raw_prepared = {}
    wrapper_prepared = {}
    finals = {}
    _p("Warmup / compile (not timed)...")
    for variant in variants:
        raw_prepared[variant] = _prepare(spec, variant, "raw")
        wrapper_prepared[variant] = _prepare(spec, variant, "wrapper")
        finals[variant] = _run(raw_prepared[variant])
        wrapper_final = _run(wrapper_prepared[variant])
        langs = ",".join(_languages_for(spec, variant, steps))
        _p(f"  {variant:7s} final={finals[variant]!r}  languages={langs}")
        if not _values_equal(wrapper_final, finals[variant]):
            raise RuntimeError(
                f"{variant} raw={finals[variant]!r} wrapper={wrapper_final!r} disagree"
            )

    python_final = finals["python"]
    mismatch = []
    for variant, value in finals.items():
        if not _values_equal(value, python_final):
            mismatch.append(f"{variant}={value!r}")
    if "expect" in spec and not _values_equal(python_final, spec.get("expect")):
        mismatch.append(f"python={python_final!r} vs expect={spec.get('expect')!r}")
    if mismatch:
        _p("VERIFY FAIL: finals do not match: " + ", ".join(mismatch))
        return 1
    _p(f"Verify: all variants and both paths match (final={python_final!r})")

    raw_loops = _calibrate(raw_prepared["python"], 0.25, 800, 20000)
    wrapper_loops = _calibrate(wrapper_prepared["c"], 0.25, 200, 600)
    _p(f"Raw path iterations: {raw_loops}  (runs={raw_runs})")
    _p(f"Wrapper path iterations: {wrapper_loops}  (runs={wrapper_runs})")

    _p("Path: raw (pre-resolved ctypes handles)")
    raw_results = {}
    for variant in variants:
        raw_results[variant] = _time_variant(
            f"raw/{variant}", raw_prepared[variant], python_final, steps, raw_loops, raw_runs
        )
    _summarize("raw", variants, raw_results, steps)

    _p("Path: wrapper (call_c/call_rust, per-call source read)")
    wrapper_results = {}
    for variant in variants:
        wrapper_results[variant] = _time_variant(
            f"wrapper/{variant}", wrapper_prepared[variant], python_final, steps, wrapper_loops, wrapper_runs
        )
    _summarize("wrapper", variants, wrapper_results, steps)
    _p("Times exclude compile and library lookup. One machine. Not part of the hash.")
    return 0


def main(argv=None):
    _prepare_path()
    os.chdir(ROOT)
    if str(ROOT) not in sys.path:
        sys.path.insert(0, str(ROOT))
    argv = list(sys.argv[1:] if argv is None else argv)
    if not argv:
        argv = [
            "examples/chain_health_math.json",
            "examples/chain_physics_math.json",
            "examples/chain_math_heavy.json",
            "examples/chain_cheap.json",
            "examples/chain_cheap_reordered.json",
        ]
    status = 0
    for index, path in enumerate(argv):
        if index:
            _p()
        try:
            code = time_chain(path)
        except Exception as exc:
            _p(f"ERROR: {exc}")
            return 1
        if code:
            status = code
    return status


if __name__ == "__main__":
    sys.exit(main())
