// xylem:job xylem:math.log_safe
// xylem:function log_safe_c
// xylem:signature double(double)

#include <math.h>

double log_safe_c(double x) {
    if (!isfinite(x) || x <= 0.0) { return NAN; }
    return log(x);
}
