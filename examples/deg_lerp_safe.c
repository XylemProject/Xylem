// xylem:job xylem:math.deg_lerp_safe
// xylem:function deg_lerp_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

static double euclid_mod(double x, double period) {
    double r = fmod(x, period);
    if ((r < 0.0 && period > 0.0) || (r > 0.0 && period < 0.0)) {
        r += period;
    }
    return r;
}

double deg_lerp_safe_c(double a, double b, double t) {
    if (!isfinite(a) || !isfinite(b) || !isfinite(t)) {
        return NAN;
    }
    const double turn = 360.0;
    const double half = 180.0;
    double d = euclid_mod(b - a + half, turn) - half;
    return a + d * t;
}
