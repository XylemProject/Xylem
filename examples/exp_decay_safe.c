// xylem:job xylem:math.exp_decay_safe
// xylem:function exp_decay_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

double exp_decay_safe_c(double value, double rate, double t) {
    if (!isfinite(value) || !isfinite(rate) || !isfinite(t)) {
        return NAN;
    }
    if (t < 0.0) {
        return NAN;
    }
    return value * exp(-rate * t);
}
