// xylem:job xylem:math.diff
// xylem:function diff_c
// xylem:signature double(double, double)

double diff_c(double x, double y) {
    if (x >= y) {
        return x - y;
    }
    return y - x;
}
