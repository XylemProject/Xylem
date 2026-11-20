// xylem:job xylem:health.apply_damage
// xylem:function apply_damage_c
// xylem:signature double(double, double)

double apply_damage_c(double health, double amount) {
    health = health - amount;
    if (health < 0.0) {
        return 0.0;
    }
    return health;
}
