// xylem:job xylem:math.manhattan_safe
// xylem:function manhattan_safe_c
// xylem:signature double(double, double, double, double)

#include <math.h>

double manhattan_safe_c(double x1, double y1, double x2, double y2) {
    if (!isfinite(x1) || !isfinite(y1) || !isfinite(x2) || !isfinite(y2)) {
        return NAN;
    }
    return fabs(x2 - x1) + fabs(y2 - y1);
}
