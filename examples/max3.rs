// xylem:job xylem:math.max3
// xylem:function max3_rs

#[no_mangle]
pub extern "C" fn max3_rs(x: f64, y: f64, z: f64) -> f64 {
    let m = if x >= y { x } else { y };
    if m >= z { m } else { z }
}
