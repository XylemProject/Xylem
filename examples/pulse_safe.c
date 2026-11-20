// xylem:job xylem:math.pulse_safe
// xylem:function pulse_safe_c
// xylem:signature double(double, double)

#include <math.h>

double pulse_safe_c(double x, double duty) {
    if (!isfinite(x) || !isfinite(duty)) {
        return NAN;
    }
    if (duty <= 0.0 || duty >= 1.0) {
        return NAN;
    }
    double r = fmod(x, 1.0);
    if (r < 0.0) { r += 1.0; }
    return r < duty ? 1.0 : 0.0;
}
