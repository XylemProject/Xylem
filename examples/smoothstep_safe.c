// xylem:job xylem:math.smoothstep_safe
// xylem:function smoothstep_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

double smoothstep_safe_c(double edge0, double edge1, double x) {
    if (!isfinite(edge0) || !isfinite(edge1) || !isfinite(x)) {
        return NAN;
    }
    if (edge0 == edge1) {
        return NAN;
    }
    double t = (x - edge0) / (edge1 - edge0);
    if (t < 0.0) { t = 0.0; }
    if (t > 1.0) { t = 1.0; }
    return t * t * (3.0 - 2.0 * t);
}
