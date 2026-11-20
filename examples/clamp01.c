// xylem:job xylem:math.clamp01
// xylem:function clamp01_c
// xylem:signature double(double)

double clamp01_c(double x) {
    if (x < 0.0) { return 0.0; }
    if (x > 1.0) { return 1.0; }
    return x;
}
