// xylem:job xylem:math.clamp_angle_safe
// xylem:function clamp_angle_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

static double euclid_mod(double x, double period) {
    double r = fmod(x, period);
    if ((r < 0.0 && period > 0.0) || (r > 0.0 && period < 0.0)) {
        r += period;
    }
    return r;
}

double clamp_angle_safe_c(double a, double lo, double hi) {
    if (!isfinite(a) || !isfinite(lo) || !isfinite(hi)) {
        return NAN;
    }
    const double turn = 360.0;
    double span = euclid_mod(hi - lo, turn);
    double off = euclid_mod(a - lo, turn);
    if (off <= span) {
        return euclid_mod(lo + off, turn);
    }
    if (off - span <= turn - off) {
        return euclid_mod(hi, turn);
    }
    return euclid_mod(lo, turn);
}
