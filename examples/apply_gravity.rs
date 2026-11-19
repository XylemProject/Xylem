// xylem:job xylem:physics.apply_gravity
// xylem:function apply_gravity_rs

#[no_mangle]
pub extern "C" fn apply_gravity_rs(velocity_y: f64, gravity: f64, dt: f64) -> f64 {
    velocity_y + gravity * dt
}
