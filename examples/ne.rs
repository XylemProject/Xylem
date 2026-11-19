// xylem:job xylem:math.ne
// xylem:function ne_rs

#[no_mangle]
pub extern "C" fn ne_rs(x: f64, y: f64) -> bool { x != y }
