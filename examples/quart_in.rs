// xylem:job xylem:math.quart_in
// xylem:function quart_in_rs

#[no_mangle]
pub extern "C" fn quart_in_rs(t: f64) -> f64 { t * t * t * t }
