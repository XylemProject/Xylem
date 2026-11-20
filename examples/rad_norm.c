// xylem:job xylem:math.rad_norm
// xylem:function rad_norm_c
// xylem:signature double(double)

#include <math.h>

double rad_norm_c(double r) {
    const double tau = 6.28318530717958647692;
    double v = fmod(r, tau);
    if (v < 0.0) { v += tau; }
    return v;
}
