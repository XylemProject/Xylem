// xylem:job xylem:math.max3
// xylem:function max3_c
// xylem:signature double(double, double, double)

double max3_c(double x, double y, double z) {
    double m = (x >= y) ? x : y;
    return (m >= z) ? m : z;
}
