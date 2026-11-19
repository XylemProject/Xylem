// xylem:job xylem:math.log2_safe
// xylem:function log2_safe_rs

#[no_mangle]
pub extern "C" fn log2_safe_rs(x: f64) -> f64 {
    if !x.is_finite() || x <= 0.0 { return f64::NAN; }
    x.log2()
}
