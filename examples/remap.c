// xylem:job xylem:math.remap
// xylem:function remap_c
// xylem:signature double(double, double, double, double, double)

double remap_c(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) / (in_max - in_min) * (out_max - out_min) + out_min;
}
