// xylem:job xylem:math.cubic_in
// xylem:function cubic_in_rs

#[no_mangle]
pub extern "C" fn cubic_in_rs(t: f64) -> f64 {
    t * t * t
}
