import hashlib
import math
import os
import re
import subprocess
import time

_loaded = {}

_SIGNATURE_RE = re.compile(
    r"^//\s*xylem:signature\s+([A-Za-z_][A-Za-z0-9_]*)\s*\((.*)\)\s*$"
)


def _source_digest(source_file: str) -> str:
    with open(source_file, "rb") as f:
        return hashlib.sha256(f.read()).hexdigest()[:8]


def _source_text(source_file: str) -> str:
    with open(source_file, "r", encoding="utf-8") as f:
        return f.read()


def _normalize_c_type(name: str) -> str:
    name = (name or "").strip().lower()
    if name == "int":
        return "int"
    if name in ("double", "float"):
        return "double"
    raise RuntimeError(f"Unsupported C signature type: {name}")


def parse_c_signature(source_file: str, arg_count: int):
    """Return (return_kind, arg_kinds). No marker means all ints."""
    text = _source_text(source_file)
    parsed = None
    for line in text.splitlines():
        match = _SIGNATURE_RE.match(line.strip())
        if match:
            parsed = match
            break
    if parsed is None:
        return "int", ["int"] * arg_count
    ret_kind = _normalize_c_type(parsed.group(1))
    raw_args = parsed.group(2).strip()
    if not raw_args:
        arg_kinds = []
    else:
        arg_kinds = [_normalize_c_type(part) for part in raw_args.split(",")]
    if len(arg_kinds) != arg_count:
        raise RuntimeError(
            f"C signature has {len(arg_kinds)} argument types, but {arg_count} were provided"
        )
    return ret_kind, arg_kinds


def _ctype(kind: str):
    import ctypes
    if kind == "double":
        return ctypes.c_double
    return ctypes.c_int


def _encode_arg(item, kind: str):
    if item is None:
        if kind == "double":
            return float("nan")
        raise TypeError("None arg is only supported on double C backends")
    if kind == "double":
        return float(item)
    return int(item)


def _decode_result(raw, kind: str):
    if kind == "double":
        result = float(raw)
        if math.isnan(result):
            return None
        if result.is_integer() and abs(result) < 2**53:
            return int(result)
        return result
    return int(raw)


def c_values_equal(result, expected) -> bool:
    """Exact match for ints and None; allow tiny float noise."""
    if result == expected:
        return True
    if result is None or expected is None:
        return False
    try:
        return math.isclose(float(result), float(expected), rel_tol=0.0, abs_tol=1e-12)
    except (TypeError, ValueError):
        return False


def load_c(source_file: str, function_name: str, arg_count: int):
    """Compile once and return a callable. Does not download a compiler."""
    if not source_file or not os.path.isfile(source_file):
        raise FileNotFoundError(f"C source not found: {source_file}")
    digest = _source_digest(source_file)
    key = (os.path.abspath(source_file), function_name, arg_count, digest)
    if key in _loaded:
        return _loaded[key]
    ret_kind, arg_kinds = parse_c_signature(source_file, arg_count)
    gcc = find_gcc()
    if not gcc:
        raise RuntimeError("C backend requested, no gcc or clang on PATH")
    build_dir = os.path.join(os.getcwd(), "build")
    os.makedirs(build_dir, exist_ok=True)
    safe = "".join(ch if ch.isalnum() or ch in "-_" else "_" for ch in function_name) or "fn"
    dll_path = os.path.join(build_dir, f"xylem_c_{safe}_{digest}.dll")
    command = [gcc, "-shared", "-o", dll_path, source_file, "-Wl,--export-all-symbols"]
    built = subprocess.run(command, capture_output=True, text=True)
    if built.returncode != 0:
        # Windows may lock a prior DLL; fall back to a unique output path.
        dll_path = os.path.join(build_dir, f"xylem_c_{safe}_{digest}_{os.getpid()}.dll")
        command = [gcc, "-shared", "-o", dll_path, source_file, "-Wl,--export-all-symbols"]
        built = subprocess.run(command, capture_output=True, text=True)
        if built.returncode != 0:
            raise RuntimeError(built.stderr.strip() or "C compile failed")
    import ctypes
    lib = ctypes.CDLL(dll_path)
    raw_fn = getattr(lib, function_name)
    raw_fn.restype = _ctype(ret_kind)
    raw_fn.argtypes = [_ctype(kind) for kind in arg_kinds]

    def wrapper(*args):
        encoded = [_encode_arg(item, kind) for item, kind in zip(args, arg_kinds)]
        return _decode_result(raw_fn(*encoded), ret_kind)

    _loaded[key] = wrapper
    return wrapper

def call_c(source_file: str, function_name: str, args: list):
    fn = load_c(source_file, function_name, len(args))
    return fn(*args)

def time_c(source_file: str, function_name: str, cases: list):
    """Time calls only. Compile happens once and is not included."""
    if not cases:
        return None
    arg_count = len(cases[0].get("args") or [])
    fn = load_c(source_file, function_name, arg_count)
    prepared = [list(case.get("args") or []) for case in cases]
    for args in prepared:
        fn(*args)
    loops = 300
    start = time.perf_counter()
    for _ in range(loops):
        for args in prepared:
            fn(*args)
    elapsed = time.perf_counter() - start
    return round((elapsed / (loops * max(len(prepared), 1))) * 1_000_000, 3)

def find_gcc():
    for name in ("gcc", "clang"):
        try:
            found = subprocess.run([name, "--version"], capture_output=True, text=True)
        except FileNotFoundError:
            continue
        if found.returncode == 0:
            return name
    return ""
