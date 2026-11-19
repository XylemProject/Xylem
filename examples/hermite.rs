// xylem:job xylem:math.hermite
// xylem:function hermite_rs

#[no_mangle]
pub extern "C" fn hermite_rs(t: f64) -> f64 { t * t * (3.0 - 2.0 * t) }
