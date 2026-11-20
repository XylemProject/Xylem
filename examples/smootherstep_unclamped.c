// xylem:job xylem:math.smootherstep_unclamped
// xylem:function smootherstep_unclamped_c
// xylem:signature double(double, double, double)

#include <math.h>

double smootherstep_unclamped_c(double edge0, double edge1, double x) {
    if (edge0 == edge1) {
        return NAN;
    }
    double t = (x - edge0) / (edge1 - edge0);
    return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}
