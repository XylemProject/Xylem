// xylem:job xylem:math.square_wave_safe
// xylem:function square_wave_safe_rs

#[no_mangle]
pub extern "C" fn square_wave_safe_rs(x: f64) -> f64 {
    if !x.is_finite() { return f64::NAN; }
    if x.rem_euclid(2.0) < 1.0 { 1.0 } else { 0.0 }
}
