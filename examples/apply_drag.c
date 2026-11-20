// xylem:job xylem:physics.apply_drag
// xylem:function apply_drag_c
// xylem:signature double(double, double, double)

double apply_drag_c(double velocity, double drag, double dt) {
    return velocity * (1.0 - drag * dt);
}
