// xylem:job xylem:math.min3
// xylem:function min3_rs

#[no_mangle]
pub extern "C" fn min3_rs(x: f64, y: f64, z: f64) -> f64 {
    let m = if x <= y { x } else { y };
    if m <= z { m } else { z }
}
