// xylem:job xylem:math.round_to
// xylem:function round_to_rs

#[no_mangle]
pub extern "C" fn round_to_rs(x: f64, step: f64) -> f64 { ((x + step / 2.0) / step).floor() * step }
