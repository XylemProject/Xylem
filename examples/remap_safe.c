// xylem:job xylem:math.remap_safe
// xylem:function remap_safe_c
// xylem:signature double(double, double, double, double, double)

#include <math.h>

double remap_safe_c(double x, double in_min, double in_max, double out_min, double out_max) {
    if (!isfinite(x) || !isfinite(in_min) || !isfinite(in_max) || !isfinite(out_min) || !isfinite(out_max)) {
        return NAN;
    }
    if (in_min == in_max) { return NAN; }
    return out_min + (out_max - out_min) * (x - in_min) / (in_max - in_min);
}
