// xylem:job xylem:math.deadzone
// xylem:function deadzone_c
// xylem:signature double(double, double)

double deadzone_c(double value, double threshold) {
    if (threshold < 0.0) {
        threshold = -threshold;
    }
    if (value < 0.0) {
        if (-value <= threshold) {
            return 0.0;
        }
        return value;
    }
    if (value <= threshold) {
        return 0.0;
    }
    return value;
}
