// xylem:job xylem:math.clamp11
// xylem:function clamp11_c
// xylem:signature double(double)

double clamp11_c(double x) {
    if (x < -1.0) { return -1.0; }
    if (x > 1.0) { return 1.0; }
    return x;
}
