// xylem:job xylem:math.min2
// xylem:function min2_rs

#[no_mangle]
pub extern "C" fn min2_rs(x: f64, y: f64) -> f64 { if x <= y { x } else { y } }
