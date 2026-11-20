// xylem:job xylem:math.trunc
// xylem:function trunc_rs

#[no_mangle]
pub extern "C" fn trunc_rs(x: f64) -> f64 {
    if !x.is_finite() { return f64::NAN; }
    x.trunc()
}
