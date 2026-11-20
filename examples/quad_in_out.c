// xylem:job xylem:math.quad_in_out
// xylem:function quad_in_out_c
// xylem:signature double(double)

double quad_in_out_c(double t) {
    if (t < 0.5) {
        return 2.0 * t * t;
    }
    return -1.0 + (4.0 - 2.0 * t) * t;
}
