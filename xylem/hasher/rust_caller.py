import hashlib
import math
import os
import stat
import subprocess
import time

_loaded = {}
_source_meta = {}
_resolve_cache = {}
_call_cache = {}
_rustc_name = None

# rustc -O is equivalent to -C opt-level=3. Include the tag in DLL names so
# stale unoptimized builds are not reused.
_RS_OPT = "-O"
_RS_OPT_TAG = "O"


def _resolve_path(source_file: str) -> str:
    cwd = os.getcwd()
    key = (source_file, cwd)
    cached = _resolve_cache.get(key)
    if cached is not None:
        return cached
    resolved = os.path.abspath(source_file)
    _resolve_cache[key] = resolved
    return resolved


def _file_ident(path: str):
    st = os.stat(path)
    if not stat.S_ISREG(st.st_mode):
        raise FileNotFoundError(f"Rust source not found: {path}")
    return (st.st_mtime_ns, st.st_size)


def _source_digest_from_text(text: str) -> str:
    hasher = hashlib.sha256()
    hasher.update(text.encode("utf-8"))
    hasher.update(b"\0opt=")
    hasher.update(_RS_OPT_TAG.encode("ascii"))
    return hasher.hexdigest()[:16]


def _cached_source(resolved: str, ident=None):
    """Return (text, digest) cached by (path, mtime_ns, size)."""
    if ident is None:
        try:
            ident = _file_ident(resolved)
        except OSError:
            return "", ""
    hit = _source_meta.get(resolved)
    if hit is not None and hit[0] == ident:
        return hit[1], hit[2]
    try:
        with open(resolved, "r", encoding="utf-8") as handle:
            text = handle.read()
    except OSError:
        return "", ""
    digest = _source_digest_from_text(text)
    _source_meta[resolved] = (ident, text, digest)
    return text, digest


def _source_text(source_file: str) -> str:
    try:
        resolved = _resolve_path(source_file)
        text, _digest = _cached_source(resolved)
        return text
    except OSError:
        return ""


def _uses_float_in_text(text: str) -> bool:
    return "f64" in text or "f32" in text


def _uses_float_args(source_file: str) -> bool:
    text = _source_text(source_file)
    return _uses_float_in_text(text)


def _abi_kind_from_text(text: str) -> str:
    for line in text.splitlines():
        if line.strip() == "// xylem:returns optional_bool":
            return "optional_bool"
    if "-> bool" in text:
        return "bool"
    if "f64" in text or "f32" in text:
        return "float"
    return "int"


def _abi_kind(source_file: str) -> str:
    """Detect ABI from the Rust source.

    - optional_bool: marker `// xylem:returns optional_bool` (i32: 1 true, 0 false, -1 None)
    - bool: signature returns bool (comparisons)
    - float: uses f64/f32 (optional NaN stands for None)
    - int: existing i32 path
    """
    return _abi_kind_from_text(_source_text(source_file))


def _encode_arg(item, kind: str):
    if item is None:
        if kind in ("float", "bool", "optional_bool"):
            return float("nan")
        raise TypeError("None arg is only supported on float/bool Rust backends")
    if kind == "int":
        return int(item)
    if kind in ("bool", "optional_bool"):
        # Match float-arg bool backends; int-arg bool backends get ints via load.
        return float(item) if not isinstance(item, bool) else float(int(item))
    # float
    return float(item)


def _decode_result(raw, kind: str):
    if kind == "optional_bool":
        value = int(raw)
        if value == 1:
            return True
        if value == 0:
            return False
        if value == -1:
            return None
        raise RuntimeError(f"optional_bool expected 1, 0, or -1, got {value}")
    if kind == "bool":
        return bool(raw)
    if kind == "float":
        result = float(raw)
        if math.isnan(result):
            return None
        if result.is_integer() and abs(result) < 2**53:
            return int(result)
        return result
    return int(raw)


def load_rust(source_file: str, function_name: str, arg_count: int):
    """Compile once and return a callable. Does not download a compiler."""
    if not source_file:
        raise FileNotFoundError(f"Rust source not found: {source_file}")
    resolved = _resolve_path(source_file)
    try:
        ident = _file_ident(resolved)
    except OSError:
        raise FileNotFoundError(f"Rust source not found: {source_file}")
    live_key = (resolved, function_name, arg_count, _RS_OPT_TAG)
    entry = _loaded.get(live_key)
    if entry is not None and entry["ident"] == ident:
        _call_cache[(source_file, function_name, arg_count)] = (resolved, ident, entry["wrapper"])
        return entry["fn"], entry["kind"]
    text, digest = _cached_source(resolved, ident)
    kind = _abi_kind_from_text(text)
    uses_float = _uses_float_in_text(text)
    if entry is not None and entry.get("digest") == digest:
        entry["ident"] = ident
        _call_cache[(source_file, function_name, arg_count)] = (resolved, ident, entry["wrapper"])
        return entry["fn"], entry["kind"]
    rustc = find_rustc()
    if not rustc:
        raise RuntimeError("Rust backend requested, no rustc on PATH")
    build_dir = os.path.join(os.getcwd(), "build")
    os.makedirs(build_dir, exist_ok=True)
    safe = "".join(ch if ch.isalnum() or ch in "-_" else "_" for ch in function_name) or "fn"
    dll_path = os.path.join(build_dir, f"xylem_rs_{safe}_{_RS_OPT_TAG}.dll")
    command = [rustc, "--crate-type", "cdylib", _RS_OPT, "-o", dll_path, source_file]
    built = subprocess.run(command, capture_output=True, text=True)
    if built.returncode != 0:
        # Windows may lock a prior DLL; fall back to a unique output path.
        dll_path = os.path.join(build_dir, f"xylem_rs_{safe}_{_RS_OPT_TAG}_{os.getpid()}.dll")
        command = [rustc, "--crate-type", "cdylib", _RS_OPT, "-o", dll_path, source_file]
        built = subprocess.run(command, capture_output=True, text=True)
        if built.returncode != 0:
            raise RuntimeError((built.stderr or built.stdout or "Rust compile failed").strip())
    import ctypes
    lib = ctypes.CDLL(dll_path)
    fn = getattr(lib, function_name)
    if kind == "optional_bool":
        fn.restype = ctypes.c_int
        if uses_float:
            fn.argtypes = [ctypes.c_double] * arg_count
        else:
            fn.argtypes = [ctypes.c_int] * arg_count
    elif kind == "bool":
        fn.restype = ctypes.c_bool
        # Bool jobs with f64 params use doubles; plain i32 bool jobs stay ints.
        if uses_float:
            fn.argtypes = [ctypes.c_double] * arg_count
        else:
            fn.argtypes = [ctypes.c_int] * arg_count
    elif kind == "float":
        fn.restype = ctypes.c_double
        fn.argtypes = [ctypes.c_double] * arg_count
    else:
        fn.restype = ctypes.c_int
        fn.argtypes = [ctypes.c_int] * arg_count
    int_bool_args = kind in ("bool", "optional_bool") and not uses_float

    if int_bool_args:
        if kind == "bool":
            def wrapper(*args, _fn=fn):
                encoded = [int(item) for item in args]
                return bool(_fn(*encoded))
        else:
            def wrapper(*args, _fn=fn, _kind=kind):
                encoded = [int(item) for item in args]
                return _decode_result(_fn(*encoded), _kind)
    else:
        def wrapper(*args, _fn=fn, _kind=kind):
            encoded = [_encode_arg(item, _kind) for item in args]
            return _decode_result(_fn(*encoded), _kind)

    _loaded[live_key] = {
        "ident": ident,
        "digest": digest,
        "fn": fn,
        "kind": kind,
        "wrapper": wrapper,
        "uses_float": uses_float,
        "int_bool_args": int_bool_args,
    }
    _call_cache[(source_file, function_name, arg_count)] = (resolved, ident, wrapper)
    return fn, kind


def call_rust(source_file: str, function_name: str, args: list):
    arg_count = len(args)
    hit = _call_cache.get((source_file, function_name, arg_count))
    if hit is not None:
        resolved, ident, wrapper = hit
        try:
            current = _file_ident(resolved)
        except OSError:
            current = None
        if current == ident:
            return wrapper(*args)
    load_rust(source_file, function_name, arg_count)
    _resolved, _ident, wrapper = _call_cache[(source_file, function_name, arg_count)]
    return wrapper(*args)


def time_rust(source_file: str, function_name: str, cases: list):
    """Time calls only. Compile happens once and is not included."""
    if not cases:
        return None
    arg_count = len(cases[0].get("args") or [])
    fn, kind = load_rust(source_file, function_name, arg_count)
    resolved = _resolve_path(source_file)
    entry = _loaded[(resolved, function_name, arg_count, _RS_OPT_TAG)]
    int_bool_args = entry["int_bool_args"]
    prepared = []
    for case in cases:
        args = case.get("args") or []
        if int_bool_args:
            prepared.append([int(item) for item in args])
        else:
            prepared.append([_encode_arg(item, kind) for item in args])
    for args in prepared:
        fn(*args)
    loops = 300
    start = time.perf_counter()
    for _ in range(loops):
        for args in prepared:
            fn(*args)
    elapsed = time.perf_counter() - start
    return round((elapsed / (loops * max(len(prepared), 1))) * 1_000_000, 3)


def find_rustc():
    global _rustc_name
    if _rustc_name:
        return _rustc_name
    try:
        found = subprocess.run(["rustc", "--version"], capture_output=True, text=True)
    except FileNotFoundError:
        return ""
    if found.returncode == 0:
        _rustc_name = "rustc"
        return "rustc"
    return ""
