// xylem:job xylem:math.saturate01
// xylem:function saturate01_rs

#[no_mangle]
pub extern "C" fn saturate01_rs(x: f64) -> f64 { x.max(0.0).min(1.0) }
