// xylem:job xylem:math.sqrt
// xylem:function sqrt_rs

#[no_mangle]
pub extern "C" fn sqrt_rs(x: f64) -> f64 { x.sqrt() }
