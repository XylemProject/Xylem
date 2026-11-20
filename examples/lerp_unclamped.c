// xylem:job xylem:math.lerp_unclamped
// xylem:function lerp_unclamped_c
// xylem:signature double(double, double, double)

double lerp_unclamped_c(double a, double b, double t) {
    return a + (b - a) * t;
}
