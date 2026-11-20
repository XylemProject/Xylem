// xylem:job xylem:math.log1p
// xylem:function log1p_c
// xylem:signature double(double)

#include <math.h>

double log1p_c(double x) {
    if (!isfinite(x) || x <= -1.0) { return NAN; }
    return log1p(x);
}
