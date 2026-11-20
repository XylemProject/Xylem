// xylem:job xylem:math.median3
// xylem:function median3_c
// xylem:signature double(double, double, double)

double median3_c(double x, double y, double z) {
    double t;
    if (x > y) { t = x; x = y; y = t; }
    if (y > z) { t = y; y = z; z = t; }
    if (x > y) { t = x; x = y; y = t; }
    return y;
}
