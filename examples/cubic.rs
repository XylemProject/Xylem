// xylem:job xylem:math.cubic
// xylem:function cubic_rs

#[no_mangle]
pub extern "C" fn cubic_rs(t: f64) -> f64 {
    t * t * t
}
