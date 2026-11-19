// xylem:job xylem:math.elastic_in
// xylem:function elastic_in_rs

#[no_mangle]
pub extern "C" fn elastic_in_rs(t: f64) -> f64 {
    if t == 0.0 { 0.0 }
    else if t == 1.0 { 1.0 }
    else { -(2.0_f64.powf(10.0 * t - 10.0)) * (t * 10.0 - 10.75).sqrt() }
}
