// xylem:job xylem:math.angle_diff
// xylem:function angle_diff_c
// xylem:signature double(double, double)

#include <math.h>

double angle_diff_c(double a, double b) {
    const double pi = 3.14159265358979323846;
    const double tau = 2.0 * pi;
    double r = fmod(b - a + pi, tau);
    if (r < 0.0) { r += tau; }
    return r - pi;
}
