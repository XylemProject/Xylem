// xylem:job xylem:math.smoothstep
// xylem:function smoothstep_c
// xylem:signature double(double, double, double)

double smoothstep_c(double edge0, double edge1, double x) {
    double t = (x - edge0) / (edge1 - edge0);
    if (t < 0.0) { t = 0.0; }
    if (t > 1.0) { t = 1.0; }
    return t * t * (3.0 - 2.0 * t);
}
