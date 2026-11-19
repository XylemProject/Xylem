// xylem:job xylem:math.min_value
// xylem:function min_rs

#[no_mangle]
pub extern "C" fn min_rs(left: i32, right: i32) -> i32 {
    if left < right {
        return left;
    }
    right
}
