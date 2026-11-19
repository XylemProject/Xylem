// xylem:job xylem:math.quad_out
// xylem:function quad_out_rs

#[no_mangle]
pub extern "C" fn quad_out_rs(t: f64) -> f64 { t * (2.0 - t) }
