// xylem:job xylem:math.negative
// xylem:function negative_rs

#[no_mangle]
pub extern "C" fn negative_rs(x: f64) -> bool { x < 0.0 }
