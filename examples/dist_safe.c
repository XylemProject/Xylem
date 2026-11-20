// xylem:job xylem:math.dist_safe
// xylem:function dist_safe_c
// xylem:signature double(double, double, double, double)

#include <math.h>

double dist_safe_c(double x1, double y1, double x2, double y2) {
    if (!isfinite(x1) || !isfinite(y1) || !isfinite(x2) || !isfinite(y2)) {
        return NAN;
    }
    return hypot(x2 - x1, y2 - y1);
}
