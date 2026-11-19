// xylem:job xylem:math.asin_deg
// xylem:function asin_deg_rs

#[no_mangle]
pub extern "C" fn asin_deg_rs(x: f64) -> f64 {
    if x < -1.0 || x > 1.0 { return f64::NAN; }
    x.asin().to_degrees()
}
