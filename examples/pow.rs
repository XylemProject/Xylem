// xylem:job xylem:math.pow
// xylem:function pow_rs

#[no_mangle]
pub extern "C" fn pow_rs(x: f64, y: f64) -> f64 { x.powf(y) }
