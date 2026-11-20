// xylem:job xylem:math.in_range
// xylem:function in_range_c
// xylem:signature int(double, double, double)
// xylem:returns optional_bool

int in_range_c(double x, double low, double high) {
    return (low <= x && x <= high) ? 1 : 0;
}
