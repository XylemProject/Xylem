// xylem:job xylem:math.sine_out
// xylem:function sine_out_rs

#[no_mangle]
pub extern "C" fn sine_out_rs(t: f64) -> f64 { (t * std::f64::consts::FRAC_PI_2).sin() }
