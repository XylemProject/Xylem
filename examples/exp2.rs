// xylem:job xylem:math.exp2
// xylem:function exp2_rs

#[no_mangle]
pub extern "C" fn exp2_rs(x: f64) -> f64 {
    2.0_f64.powf(x)
}
