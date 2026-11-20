// xylem:job xylem:math.wrap_pi
// xylem:function wrap_pi_c
// xylem:signature double(double)

#include <math.h>

double wrap_pi_c(double a) {
    const double pi = 3.14159265358979323846;
    const double tau = 2.0 * pi;
    double r = fmod(a, tau);
    if (r < 0.0) { r += tau; }
    if (r > pi) { r -= tau; }
    return r;
}
