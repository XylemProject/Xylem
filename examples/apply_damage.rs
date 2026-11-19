// xylem:job xylem:health.apply_damage
// xylem:function apply_damage_rs

#[no_mangle]
pub extern "C" fn apply_damage_rs(health: i32, amount: i32) -> i32 {
    let health = health - amount;
    if health < 0 {
        return 0;
    }
    health
}
