// xylem:job xylem:math.saturate01
// xylem:function saturate01_c
// xylem:signature double(double)

double saturate01_c(double x) {
    if (x < 0.0) { return 0.0; }
    if (x > 1.0) { return 1.0; }
    return x;
}
