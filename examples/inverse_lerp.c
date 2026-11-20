// xylem:job xylem:math.inverse_lerp
// xylem:function inverse_lerp_c
// xylem:signature double(double, double, double)

double inverse_lerp_c(double a, double b, double x) {
    return (x - a) / (b - a);
}
