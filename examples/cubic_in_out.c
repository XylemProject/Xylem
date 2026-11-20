// xylem:job xylem:math.cubic_in_out
// xylem:function cubic_in_out_c
// xylem:signature double(double)

double cubic_in_out_c(double t) {
    if (t < 0.5) {
        return 4.0 * t * t * t;
    }
    {
        double u = 1.0 - t;
        return 1.0 - 4.0 * u * u * u;
    }
}
