// xylem:job xylem:math.wrap_value
// xylem:function wrap_value_rs

#[no_mangle]
pub extern "C" fn wrap_value_rs(value: i32, low: i32, high: i32) -> i32 {
    let span = high - low;
    if span == 0 {
        return low;
    }
    let offset = value - low;
    low + offset.rem_euclid(span)
}
