// xylem:job xylem:math.square
// xylem:function square_rs

#[no_mangle]
pub extern "C" fn square_rs(value: i32) -> i32 {
    value * value
}
