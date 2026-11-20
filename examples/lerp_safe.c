// xylem:job xylem:math.lerp_safe
// xylem:function lerp_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

double lerp_safe_c(double start, double end, double t) {
    if (!isfinite(start) || !isfinite(end) || !isfinite(t)) { return NAN; }
    return start + (end - start) * t;
}
