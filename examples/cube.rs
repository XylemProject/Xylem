// xylem:job xylem:math.cube
// xylem:function cube_rs

#[no_mangle]
pub extern "C" fn cube_rs(x: f64) -> f64 {
    x * x * x
}
