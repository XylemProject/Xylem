// xylem:job xylem:math.lt
// xylem:function lt_rs

#[no_mangle]
pub extern "C" fn lt_rs(x: f64, y: f64) -> bool { x < y }
