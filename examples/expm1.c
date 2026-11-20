// xylem:job xylem:math.expm1
// xylem:function expm1_c
// xylem:signature double(double)

#include <math.h>

double expm1_c(double x) {
    if (!isfinite(x)) { return NAN; }
    return expm1(x);
}
