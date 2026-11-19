// xylem:job xylem:math.inverse_sqrt
// xylem:function inverse_sqrt_rs

#[no_mangle]
pub extern "C" fn inverse_sqrt_rs(x: f64) -> f64 { 1.0 / x.sqrt() }
