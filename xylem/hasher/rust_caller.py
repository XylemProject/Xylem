import math
import os
import subprocess
import time

_loaded = {}

# rustc -O is equivalent to -C opt-level=3. Include the tag in DLL names so
# stale unoptimized builds are not reused.
_RS_OPT = "-O"
_RS_OPT_TAG = "O"


def _source_text(source_file: str) -> str:
    try:
        with open(source_file, "r", encoding="utf-8") as f:
            return f.read()
    except OSError:
        return ""


def _uses_float_args(source_file: str) -> bool:
    text = _source_text(source_file)
    return "f64" in text or "f32" in text


def _abi_kind(source_file: str) -> str:
    """Detect ABI from the Rust source.

    - optional_bool: marker `// xylem:returns optional_bool` (i32: 1 true, 0 false, -1 None)
    - bool: signature returns bool (comparisons)
    - float: uses f64/f32 (optional NaN stands for None)
    - int: existing i32 path
    """
    text = _source_text(source_file)
    for line in text.splitlines():
        if line.strip() == "// xylem:returns optional_bool":
            return "optional_bool"
    if "-> bool" in text:
        return "bool"
    if "f64" in text or "f32" in text:
        return "float"
    return "int"


def load_rust(source_file: str, function_name: str, arg_count: int):
    """Compile once and return a callable. Does not download a compiler."""
    if not source_file or not os.path.isfile(source_file):
        raise FileNotFoundError(f"Rust source not found: {source_file}")
    kind = _abi_kind(source_file)
    key = (os.path.abspath(source_file), function_name, arg_count, kind, _RS_OPT_TAG)
    if key in _loaded:
        return _loaded[key]
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
        if _uses_float_args(source_file):
            fn.argtypes = [ctypes.c_double] * arg_count
        else:
            fn.argtypes = [ctypes.c_int] * arg_count
    elif kind == "bool":
        fn.restype = ctypes.c_bool
        # Bool jobs with f64 params use doubles; plain i32 bool jobs stay ints.
        if _uses_float_args(source_file):
            fn.argtypes = [ctypes.c_double] * arg_count
        else:
            fn.argtypes = [ctypes.c_int] * arg_count
    elif kind == "float":
        fn.restype = ctypes.c_double
        fn.argtypes = [ctypes.c_double] * arg_count
    else:
        fn.restype = ctypes.c_int
        fn.argtypes = [ctypes.c_int] * arg_count
    _loaded[key] = (fn, kind)
    return _loaded[key]


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


def call_rust(source_file: str, function_name: str, args: list):
    fn, kind = load_rust(source_file, function_name, len(args))
    # For bool / optional_bool backends that use i32 args, encode as int.
    if kind in ("bool", "optional_bool") and not _uses_float_args(source_file):
        encoded = [int(item) for item in args]
        if kind == "bool":
            return bool(fn(*encoded))
        return _decode_result(fn(*encoded), kind)
    encoded = [_encode_arg(item, kind) for item in args]
    return _decode_result(fn(*encoded), kind)


def time_rust(source_file: str, function_name: str, cases: list):
    """Time calls only. Compile happens once and is not included."""
    if not cases:
        return None
    arg_count = len(cases[0].get("args") or [])
    fn, kind = load_rust(source_file, function_name, arg_count)
    prepared = []
    for case in cases:
        args = case.get("args") or []
        if kind in ("bool", "optional_bool") and not _uses_float_args(source_file):
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
    try:
        found = subprocess.run(["rustc", "--version"], capture_output=True, text=True)
    except FileNotFoundError:
        return ""
    if found.returncode == 0:
        return "rustc"
    return ""
