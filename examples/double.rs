// xylem:job xylem:math.double
// xylem:function double_rs

#[no_mangle]
pub extern "C" fn double_rs(x: f64) -> f64 {
    x * 2.0
}
