// xylem:job xylem:math.smoothstep_unclamped
// xylem:function smoothstep_unclamped_c
// xylem:signature double(double, double, double)

#include <math.h>

double smoothstep_unclamped_c(double edge0, double edge1, double x) {
    if (edge0 == edge1) {
        return NAN;
    }
    double t = (x - edge0) / (edge1 - edge0);
    return t * t * (3.0 - 2.0 * t);
}
