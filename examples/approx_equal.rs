// xylem:job xylem:math.approx_equal
// xylem:function approx_equal_rs
// xylem:returns optional_bool

#[no_mangle]
pub extern "C" fn approx_equal_rs(x: f64, y: f64, eps: f64) -> i32 {
    if !x.is_finite() || !y.is_finite() || !eps.is_finite() || eps < 0.0 {
        return -1;
    }
    if (x - y).abs() <= eps { 1 } else { 0 }
}
