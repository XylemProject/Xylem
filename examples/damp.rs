// xylem:job xylem:math.damp
// xylem:function damp_rs

#[no_mangle]
pub extern "C" fn damp_rs(current: f64, target: f64, rate: f64, dt: f64) -> f64 {
    current + (target - current) * (1.0 - (-rate * dt).exp())
}
