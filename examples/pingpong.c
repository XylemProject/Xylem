// xylem:job xylem:math.pingpong
// xylem:function pingpong_c
// xylem:signature double(double, double)

#include <math.h>

double pingpong_c(double x, double length) {
    double period = 2.0 * length;
    double r = fmod(x, period);
    if ((r < 0.0 && period > 0.0) || (r > 0.0 && period < 0.0)) {
        r += period;
    }
    return fabs(r - length);
}
