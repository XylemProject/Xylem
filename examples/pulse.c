// xylem:job xylem:math.pulse
// xylem:function pulse_c
// xylem:signature double(double, double, double)

double pulse_c(double x, double low, double high) {
    return (low <= x && x <= high) ? 1.0 : 0.0;
}
