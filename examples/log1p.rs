// xylem:job xylem:math.log1p
// xylem:function log1p_rs

#[no_mangle]
pub extern "C" fn log1p_rs(x: f64) -> f64 {
    if !x.is_finite() || x <= -1.0 { return f64::NAN; }
    x.ln_1p()
}
