// xylem:job xylem:math.dec
// xylem:function dec_rs

#[no_mangle]
pub extern "C" fn dec_rs(x: f64) -> f64 {
    x - 1.0
}
