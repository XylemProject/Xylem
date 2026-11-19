// xylem:job xylem:math.exp
// xylem:function exp_rs

#[no_mangle]
pub extern "C" fn exp_rs(x: f64) -> f64 {
    x.exp()
}
