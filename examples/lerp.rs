// xylem:job xylem:math.lerp
// xylem:function lerp_rs

#[no_mangle]
pub extern "C" fn lerp_rs(start: f64, end: f64, t: f64) -> f64 {
    start + (end - start) * t
}
