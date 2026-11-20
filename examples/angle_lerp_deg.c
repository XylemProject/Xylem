// xylem:job xylem:math.angle_lerp_deg
// xylem:function angle_lerp_deg_c
// xylem:signature double(double, double, double)

#include <math.h>

static double euclid_mod(double x, double period) {
    double r = fmod(x, period);
    if ((r < 0.0 && period > 0.0) || (r > 0.0 && period < 0.0)) {
        r += period;
    }
    return r;
}

double angle_lerp_deg_c(double a, double b, double t) {
    const double turn = 360.0;
    const double half = 180.0;
    double diff = euclid_mod(b - a + half, turn) - half;
    return euclid_mod(a + diff * t, turn);
}
