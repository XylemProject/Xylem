// xylem:job xylem:math.mix_safe
// xylem:function mix_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

double mix_safe_c(double a, double b, double t) {
    if (!isfinite(a) || !isfinite(b) || !isfinite(t)) {
        return NAN;
    }
    return a + (b - a) * t;
}
