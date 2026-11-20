// xylem:job xylem:math.approx_equal
// xylem:function approx_equal_rs

// Existing bool Rust backends (eq, ne, etc.) never return None, and the
// bool ABI has no NaN-as-None path. Use f64 1.0/0.0/NAN so None is representable.
#[no_mangle]
pub extern "C" fn approx_equal_rs(x: f64, y: f64, eps: f64) -> f64 {
    if !x.is_finite() || !y.is_finite() || !eps.is_finite() || eps < 0.0 {
        return f64::NAN;
    }
    if (x - y).abs() <= eps { 1.0 } else { 0.0 }
}
