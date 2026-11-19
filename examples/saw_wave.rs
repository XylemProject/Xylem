// xylem:job xylem:math.saw_wave
// xylem:function saw_wave_rs

#[no_mangle]
pub extern "C" fn saw_wave_rs(x: f64) -> f64 { x - x.floor() }
