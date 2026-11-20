// xylem:job xylem:math.sign_or_zero
// xylem:function sign_or_zero_c
// xylem:signature double(double)

double sign_or_zero_c(double x) {
    if (x < 0.0) { return -1.0; }
    if (x > 0.0) { return 1.0; }
    return 0.0;
}
