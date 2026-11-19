// xylem:job xylem:math.inc
// xylem:function inc_rs

#[no_mangle]
pub extern "C" fn inc_rs(x: f64) -> f64 { x + 1.0 }
