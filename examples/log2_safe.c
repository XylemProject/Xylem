// xylem:job xylem:math.log2_safe
// xylem:function log2_safe_c
// xylem:signature double(double)

#include <math.h>

double log2_safe_c(double x) {
    if (!isfinite(x) || x <= 0.0) { return NAN; }
    return log2(x);
}
