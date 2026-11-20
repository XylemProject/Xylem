// xylem:job xylem:math.smootherstep_safe
// xylem:function smootherstep_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

double smootherstep_safe_c(double edge0, double edge1, double x) {
    if (!isfinite(edge0) || !isfinite(edge1) || !isfinite(x)) { return NAN; }
    if (edge0 == edge1) { return NAN; }
    double t = (x - edge0) / (edge1 - edge0);
    if (t < 0.0) { return 0.0; }
    if (t > 1.0) { return 1.0; }
    return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}
