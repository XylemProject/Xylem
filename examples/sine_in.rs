// xylem:job xylem:math.sine_in
// xylem:function sine_in_rs

#[no_mangle]
pub extern "C" fn sine_in_rs(t: f64) -> f64 { 1.0 - (t * std::f64::consts::FRAC_PI_2).cos() }
