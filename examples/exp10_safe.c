// xylem:job xylem:math.exp10_safe
// xylem:function exp10_safe_c
// xylem:signature double(double)

#include <math.h>

double exp10_safe_c(double x) {
    if (!isfinite(x)) {
        return NAN;
    }
    double result = pow(10.0, x);
    if (!isfinite(result)) {
        return NAN;
    }
    return result;
}
