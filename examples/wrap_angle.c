// xylem:job xylem:math.wrap_angle
// xylem:function wrap_angle_c
// xylem:signature double(double)

#include <math.h>

double wrap_angle_c(double a) {
    const double pi = 3.14159265358979323846;
    const double tau = 2.0 * pi;
    double r = fmod(a + pi, tau);
    if (r < 0.0) { r += tau; }
    return r - pi;
}
