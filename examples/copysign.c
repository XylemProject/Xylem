// xylem:job xylem:math.copysign
// xylem:function copysign_c
// xylem:signature double(double, double)

#include <math.h>

double copysign_c(double x, double y) {
    if (!isfinite(x) || !isfinite(y)) { return NAN; }
    if (y < 0.0) { return -fabs(x); }
    return fabs(x);
}
