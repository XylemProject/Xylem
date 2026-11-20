// xylem:job xylem:math.remainder
// xylem:function remainder_c
// xylem:signature double(double, double)

#include <math.h>

double remainder_c(double x, double y) {
    if (!isfinite(x) || !isfinite(y) || y == 0.0) { return NAN; }
    return remainder(x, y);
}
