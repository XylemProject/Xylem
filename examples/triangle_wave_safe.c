// xylem:job xylem:math.triangle_wave_safe
// xylem:function triangle_wave_safe_c
// xylem:signature double(double)

#include <math.h>

double triangle_wave_safe_c(double x) {
    double r;
    if (!isfinite(x)) { return NAN; }
    r = fmod(x, 1.0);
    if (r < 0.0) { r += 1.0; }
    return 1.0 - fabs(2.0 * r - 1.0);
}
