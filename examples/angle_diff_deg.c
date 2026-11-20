// xylem:job xylem:math.angle_diff_deg
// xylem:function angle_diff_deg_c
// xylem:signature double(double, double)

#include <math.h>

double angle_diff_deg_c(double a, double b) {
    const double turn = 360.0;
    const double half = 180.0;
    double r = fmod(b - a + half, turn);
    if (r < 0.0) { r += turn; }
    double d = r - half;
    if (d == -180.0) {
        d = 180.0;
    }
    return d;
}
