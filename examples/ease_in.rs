// xylem:job xylem:math.ease_in
// xylem:function ease_in_rs

#[no_mangle]
pub extern "C" fn ease_in_rs(t: f64) -> f64 {
    t * t
}
