// xylem:job xylem:math.saturate_safe
// xylem:function saturate_safe_c
// xylem:signature double(double)

#include <math.h>

double saturate_safe_c(double value) {
    if (!isfinite(value)) {
        return NAN;
    }
    if (value < 0.0) { return 0.0; }
    if (value > 1.0) { return 1.0; }
    return value;
}
