// xylem:job xylem:math.approx_equal
// xylem:function approx_equal_c
// xylem:signature int(double, double, double)
// xylem:returns optional_bool

#include <math.h>

int approx_equal_c(double x, double y, double eps) {
    if (!isfinite(x) || !isfinite(y) || !isfinite(eps) || eps < 0.0) {
        return -1;
    }
    if (fabs(x - y) <= eps) { return 1; }
    return 0;
}
