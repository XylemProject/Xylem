// xylem:job xylem:math.fract
// xylem:function fract_rs

#[no_mangle]
pub extern "C" fn fract_rs(x: f64) -> f64 {
    x - x.floor()
}
