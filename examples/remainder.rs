// xylem:job xylem:math.remainder
// xylem:function remainder_rs

#[no_mangle]
pub extern "C" fn remainder_rs(x: f64, y: f64) -> f64 {
    if !x.is_finite() || !y.is_finite() || y == 0.0 { return f64::NAN; }
    x - (x / y).round_ties_even() * y
}
