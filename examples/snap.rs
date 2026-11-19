// xylem:job xylem:math.snap
// xylem:function snap_rs

#[no_mangle]
pub extern "C" fn snap_rs(x: f64, step: f64) -> f64 { ((x + step / 2.0) / step).floor() * step }
