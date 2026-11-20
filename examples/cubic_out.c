// xylem:job xylem:math.cubic_out
// xylem:function cubic_out_c
// xylem:signature double(double)

double cubic_out_c(double t) {
    double u = 1.0 - t;
    return 1.0 - u * u * u;
}
