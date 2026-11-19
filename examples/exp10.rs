// xylem:job xylem:math.exp10
// xylem:function exp10_rs

#[no_mangle]
pub extern "C" fn exp10_rs(x: f64) -> f64 {
    10.0_f64.powf(x)
}
