// xylem:job xylem:math.ease_out
// xylem:function ease_out_rs

#[no_mangle]
pub extern "C" fn ease_out_rs(t: f64) -> f64 {
    t * (2.0 - t)
}
