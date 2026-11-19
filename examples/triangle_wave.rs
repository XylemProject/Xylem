// xylem:job xylem:math.triangle_wave
// xylem:function triangle_wave_rs

#[no_mangle]
pub extern "C" fn triangle_wave_rs(x: f64) -> f64 { 1.0 - (2.0 * x.rem_euclid(1.0) - 1.0).abs() }
