// xylem:job xylem:math.abs_value
// xylem:function abs_rs

#[no_mangle]
pub extern "C" fn abs_rs(value: i32) -> i32 {
    if value < 0 {
        return -value;
    }
    value
}
