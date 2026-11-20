// xylem:job xylem:math.bias_safe
// xylem:function bias_safe_c
// xylem:signature double(double, double)

#include <math.h>

double bias_safe_c(double x, double bias) {
    if (!isfinite(x) || !isfinite(bias)) {
        return NAN;
    }
    return pow(x, log(bias) / log(0.5));
}
