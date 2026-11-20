import hashlib
import os
import subprocess
import time

_loaded = {}


def _source_digest(source_file: str) -> str:
    with open(source_file, "rb") as f:
        return hashlib.sha256(f.read()).hexdigest()[:8]


def load_c(source_file: str, function_name: str, arg_count: int):
    """Compile once and return a callable. Does not download a compiler."""
    if not source_file or not os.path.isfile(source_file):
        raise FileNotFoundError(f"C source not found: {source_file}")
    key = (os.path.abspath(source_file), function_name, arg_count)
    if key in _loaded:
        return _loaded[key]
    gcc = find_gcc()
    if not gcc:
        raise RuntimeError("C backend requested, no gcc or clang on PATH")
    build_dir = os.path.join(os.getcwd(), "build")
    os.makedirs(build_dir, exist_ok=True)
    safe = "".join(ch if ch.isalnum() or ch in "-_" else "_" for ch in function_name) or "fn"
    digest = _source_digest(source_file)
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
    fn = getattr(lib, function_name)
    fn.restype = ctypes.c_int
    fn.argtypes = [ctypes.c_int] * arg_count
    _loaded[key] = fn
    return fn

def call_c(source_file: str, function_name: str, args: list):
    fn = load_c(source_file, function_name, len(args))
    return int(fn(*[int(item) for item in args]))

def time_c(source_file: str, function_name: str, cases: list):
    """Time calls only. Compile happens once and is not included."""
    if not cases:
        return None
    arg_count = len(cases[0].get("args") or [])
    fn = load_c(source_file, function_name, arg_count)
    prepared = [[int(item) for item in case.get("args") or []] for case in cases]
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
