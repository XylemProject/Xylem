// xylem:job xylem:math.fmod
// xylem:function fmod_rs

#[no_mangle]
pub extern "C" fn fmod_rs(x: f64, y: f64) -> f64 {
    if !x.is_finite() || !y.is_finite() || y == 0.0 { return f64::NAN; }
    x % y
}
