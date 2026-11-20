// xylem:job xylem:math.map_range
// xylem:function map_range_c
// xylem:signature double(double, double, double, double, double)

double map_range_c(double value, double in_min, double in_max, double out_min, double out_max) {
    if (in_max == in_min) {
        return out_min;
    }
    double t = (value - in_min) / (in_max - in_min);
    return out_min + (out_max - out_min) * t;
}
