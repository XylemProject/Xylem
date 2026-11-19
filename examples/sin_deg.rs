// xylem:job xylem:math.sin_deg
// xylem:function sin_deg_rs

#[no_mangle]
pub extern "C" fn sin_deg_rs(d: f64) -> f64 { d.to_radians().sin() }
