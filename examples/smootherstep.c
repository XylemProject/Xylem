// xylem:job xylem:math.smootherstep
// xylem:function smootherstep_c
// xylem:signature double(double, double, double)

double smootherstep_c(double edge0, double edge1, double x) {
    double t = (x - edge0) / (edge1 - edge0);
    if (t < 0.0) {
        return 0.0;
    }
    if (t > 1.0) {
        return 1.0;
    }
    return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}
