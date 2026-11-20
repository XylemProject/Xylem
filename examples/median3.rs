// xylem:job xylem:math.median3
// xylem:function median3_rs

#[no_mangle]
pub extern "C" fn median3_rs(x: f64, y: f64, z: f64) -> f64 {
    let mut x = x;
    let mut y = y;
    let mut z = z;
    if x > y {
        let t = x;
        x = y;
        y = t;
    }
    if y > z {
        let t = y;
        y = z;
        z = t;
    }
    if x > y {
        let t = x;
        x = y;
        y = t;
    }
    y
}
