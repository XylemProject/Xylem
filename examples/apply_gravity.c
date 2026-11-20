// xylem:job xylem:physics.apply_gravity
// xylem:function apply_gravity_c
// xylem:signature double(double, double, double)

double apply_gravity_c(double velocity_y, double gravity, double dt) {
    return velocity_y + gravity * dt;
}
