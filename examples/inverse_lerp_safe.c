// xylem:job xylem:math.inverse_lerp_safe
// xylem:function inverse_lerp_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

double inverse_lerp_safe_c(double a, double b, double x) {
    if (!isfinite(a) || !isfinite(b) || !isfinite(x) || a == b) {
        return NAN;
    }
    return (x - a) / (b - a);
}
