// xylem:job xylem:math.ceil_to
// xylem:function ceil_to_rs

#[no_mangle]
pub extern "C" fn ceil_to_rs(x: i32, step: i32) -> i32 {
    ((x + step - 1) / step) * step
}
