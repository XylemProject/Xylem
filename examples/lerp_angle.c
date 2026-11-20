// xylem:job xylem:math.lerp_angle
// xylem:function lerp_angle_c
// xylem:signature double(double, double, double)

#include <math.h>

static double euclid_mod(double x, double period) {
    double r = fmod(x, period);
    if ((r < 0.0 && period > 0.0) || (r > 0.0 && period < 0.0)) {
        r += period;
    }
    return r;
}

double lerp_angle_c(double a, double b, double t) {
    const double pi = 3.14159265358979323846;
    const double tau = 2.0 * pi;
    double d = euclid_mod(b - a + pi, tau) - pi;
    return a + d * t;
}
