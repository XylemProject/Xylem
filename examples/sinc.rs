// xylem:job xylem:math.sinc
// xylem:function sinc_rs

#[no_mangle]
pub extern "C" fn sinc_rs(x: f64) -> f64 {
    if !x.is_finite() { return f64::NAN; }
    if x == 0.0 { return 1.0; }
    x.sin() / x
}
