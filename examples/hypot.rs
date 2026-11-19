// xylem:job xylem:math.hypot
// xylem:function hypot_rs

#[no_mangle]
pub extern "C" fn hypot_rs(a: f64, b: f64) -> f64 { a.hypot(b) }
