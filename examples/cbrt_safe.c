// xylem:job xylem:math.cbrt_safe
// xylem:function cbrt_safe_c
// xylem:signature double(double)

#include <math.h>

double cbrt_safe_c(double x) {
    if (!isfinite(x)) {
        return NAN;
    }
    return copysign(pow(fabs(x), 1.0 / 3.0), x);
}
