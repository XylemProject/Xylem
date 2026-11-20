// xylem:job xylem:math.expm1
// xylem:function expm1_rs

#[no_mangle]
pub extern "C" fn expm1_rs(x: f64) -> f64 {
    if !x.is_finite() { return f64::NAN; }
    x.exp_m1()
}
