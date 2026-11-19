// xylem:job xylem:math.log10
// xylem:function log10_rs

#[no_mangle]
pub extern "C" fn log10_rs(x: f64) -> f64 {
    if x <= 0.0 { return f64::NAN; }
    x.log10()
}
