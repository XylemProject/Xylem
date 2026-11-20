// xylem:job xylem:math.gain_safe
// xylem:function gain_safe_c
// xylem:signature double(double)

#include <math.h>

double gain_safe_c(double x) {
    if (!isfinite(x)) {
        return NAN;
    }
    if (x < 0.5) {
        return 0.5 * sqrt(2.0 * x);
    }
    return 1.0 - 0.5 * sqrt(2.0 * (1.0 - x));
}
