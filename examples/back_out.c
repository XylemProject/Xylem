// xylem:job xylem:math.back_out
// xylem:function back_out_c
// xylem:signature double(double)

double back_out_c(double t) {
    double u = t - 1.0;
    return 1.0 + u * u * (2.70158 * u + 1.70158);
}
