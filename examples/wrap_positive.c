// xylem:job xylem:math.wrap_positive
// xylem:function wrap_positive_c
// xylem:signature double(double, double)

#include <math.h>

double wrap_positive_c(double x, double period) {
    double r = fmod(x, period);
    if ((r < 0.0 && period > 0.0) || (r > 0.0 && period < 0.0)) {
        r += period;
    }
    return r;
}
