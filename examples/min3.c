// xylem:job xylem:math.min3
// xylem:function min3_c
// xylem:signature double(double, double, double)

double min3_c(double x, double y, double z) {
    double m = (x <= y) ? x : y;
    return (m <= z) ? m : z;
}
