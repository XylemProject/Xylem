// xylem:job xylem:math.hypot_safe
// xylem:function hypot_safe_c
// xylem:signature double(double, double)

#include <math.h>

double hypot_safe_c(double a, double b) {
    if (!isfinite(a) || !isfinite(b)) { return NAN; }
    return hypot(a, b);
}
