// xylem:job xylem:math.atan_deg
// xylem:function atan_deg_rs

#[no_mangle]
pub extern "C" fn atan_deg_rs(x: f64) -> f64 {
    if !x.is_finite() { return f64::NAN; }
    x.atan().to_degrees()
}
