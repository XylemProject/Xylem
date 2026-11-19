// xylem:job xylem:math.sine_in_out
// xylem:function sine_in_out_rs

#[no_mangle]
pub extern "C" fn sine_in_out_rs(t: f64) -> f64 { 0.5 * (1.0 - (std::f64::consts::PI * t).cos()) }
