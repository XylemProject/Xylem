// xylem:job xylem:math.wrap_positive
// xylem:function wrap_positive_rs

#[no_mangle]
pub extern "C" fn wrap_positive_rs(x: f64, period: f64) -> f64 { x.rem_euclid(period) }
