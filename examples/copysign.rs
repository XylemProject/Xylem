// xylem:job xylem:math.copysign
// xylem:function copysign_rs

#[no_mangle]
pub extern "C" fn copysign_rs(x: f64, y: f64) -> f64 {
    if !x.is_finite() || !y.is_finite() { return f64::NAN; }
    if y < 0.0 { return -x.abs(); }
    x.abs()
}
