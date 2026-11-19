// xylem:job xylem:math.eq
// xylem:function eq_rs

#[no_mangle]
pub extern "C" fn eq_rs(x: f64, y: f64) -> bool { x == y }
