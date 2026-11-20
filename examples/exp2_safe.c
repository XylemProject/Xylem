// xylem:job xylem:math.exp2_safe
// xylem:function exp2_safe_c
// xylem:signature double(double)

#include <math.h>

double exp2_safe_c(double x) {
    if (!isfinite(x)) {
        return NAN;
    }
    double result = exp2(x);
    if (!isfinite(result)) {
        return NAN;
    }
    return result;
}
