// xylem:job xylem:math.sign_nonzero
// xylem:function sign_nonzero_c
// xylem:signature double(double)

double sign_nonzero_c(double x) {
    if (x > 0.0) { return 1.0; }
    if (x < 0.0) { return -1.0; }
    return 0.0;
}
