// xylem:job xylem:math.hypot_deg
// xylem:function hypot_deg_rs

#[no_mangle]
pub extern "C" fn hypot_deg_rs(a: f64, b: f64) -> f64 {
    let h = a.hypot(b);
    if h == 0.0 { return f64::NAN; }
    (a / h).asin().to_degrees()
}
