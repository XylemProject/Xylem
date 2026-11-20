// xylem:job xylem:math.log10_safe
// xylem:function log10_safe_c
// xylem:signature double(double)

#include <math.h>

double log10_safe_c(double x) {
    if (!isfinite(x) || x <= 0.0) { return NAN; }
    return log10(x);
}
