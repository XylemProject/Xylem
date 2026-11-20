// xylem:job xylem:health.heal
// xylem:function heal_c
// xylem:signature double(double, double, double)

double heal_c(double health, double amount, double max_health) {
    health = health + amount;
    if (health > max_health) {
        return max_health;
    }
    return health;
}
