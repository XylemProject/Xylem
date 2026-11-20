// xylem:job xylem:math.ease_in_out
// xylem:function ease_in_out_c
// xylem:signature double(double)

double ease_in_out_c(double t) {
    if (t < 0.5) {
        return 2.0 * t * t;
    }
    return -1.0 + (4.0 - 2.0 * t) * t;
}
