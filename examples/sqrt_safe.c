// xylem:job xylem:math.sqrt_safe
// xylem:function sqrt_safe_c
// xylem:signature double(double)

#include <math.h>

double sqrt_safe_c(double x) {
    if (x < 0.0) { return NAN; }
    return sqrt(x);
}
