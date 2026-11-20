// xylem:job xylem:math.step
// xylem:function step_c
// xylem:signature double(double, double)

double step_c(double edge, double x) {
    return (x < edge) ? 0.0 : 1.0;
}
