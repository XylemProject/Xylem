// xylem:job xylem:math.sqrt_safe
// xylem:function sqrt_safe_rs

#[no_mangle]
pub extern "C" fn sqrt_safe_rs(x: f64) -> f64 {
    if x < 0.0 {
        return f64::NAN;
    }
    x.sqrt()
}
