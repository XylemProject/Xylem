// xylem:job xylem:math.circ_out
// xylem:function circ_out_rs

#[no_mangle]
pub extern "C" fn circ_out_rs(t: f64) -> f64 {
    t.sqrt()
}
