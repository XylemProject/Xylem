// xylem:job xylem:math.bounce_in
// xylem:function bounce_in_c
// xylem:signature double(double)

static double bounce_out_from_in(double t) {
    if (t < 1.0 / 2.75) {
        return 7.5625 * t * t;
    }
    if (t < 2.0 / 2.75) {
        double u = t - 1.5 / 2.75;
        return 7.5625 * u * u + 0.75;
    }
    if (t < 2.5 / 2.75) {
        double u = t - 2.25 / 2.75;
        return 7.5625 * u * u + 0.9375;
    }
    {
        double u = t - 2.625 / 2.75;
        return 7.5625 * u * u + 0.984375;
    }
}

double bounce_in_c(double t) {
    return 1.0 - bounce_out_from_in(1.0 - t);
}
