// xylem:job xylem:math.damp_safe
// xylem:function damp_safe_c
// xylem:signature double(double, double, double, double)

#include <math.h>

double damp_safe_c(double current, double target, double rate, double dt) {
    if (!isfinite(current) || !isfinite(target) || !isfinite(rate) || !isfinite(dt)) {
        return NAN;
    }
    if (dt <= 0.0) {
        return NAN;
    }
    return current + (target - current) * (1.0 - exp(-rate * dt));
}
