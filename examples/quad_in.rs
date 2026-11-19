// xylem:job xylem:math.quad_in
// xylem:function quad_in_rs

#[no_mangle]
pub extern "C" fn quad_in_rs(t: f64) -> f64 { t * t }
