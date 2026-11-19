// xylem:job xylem:math.saturate_safe
// xylem:function saturate_safe_rs

#[no_mangle]
pub extern "C" fn saturate_safe_rs(value: f64) -> f64 {
    if !value.is_finite() { return f64::NAN; }
    value.clamp(0.0, 1.0)
}
