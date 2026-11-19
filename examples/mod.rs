// xylem:job xylem:math.mod
// xylem:function mod_rs

#[no_mangle]
pub extern "C" fn mod_rs(x: i32, y: i32) -> i32 {
    x.rem_euclid(y)
}
