// xylem:job xylem:math.wrap_degrees_safe
// xylem:function wrap_degrees_safe_c
// xylem:signature double(double)

#include <math.h>

double wrap_degrees_safe_c(double d) {
    double r;
    if (!isfinite(d)) { return NAN; }
    r = fmod(d + 180.0, 360.0);
    if (r < 0.0) { r += 360.0; }
    return r - 180.0;
}
