// xylem:job xylem:math.hypot_safe
// xylem:function hypot_safe_rs

#[no_mangle]
pub extern "C" fn hypot_safe_rs(a: f64, b: f64) -> f64 {
    if !(a.is_finite() && b.is_finite()) { return f64::NAN; }
    a.hypot(b)
}
