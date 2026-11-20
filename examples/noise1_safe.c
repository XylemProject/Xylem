// xylem:job xylem:math.noise1_safe
// xylem:function noise1_safe_c
// xylem:signature double(double)

#include <math.h>
#include <stdint.h>

double noise1_safe_c(double x) {
    double i, f, a, b, u;
    int64_t ii;
    if (!isfinite(x)) { return NAN; }
    i = floor(x);
    f = x - i;
    ii = (int64_t)i;
    a = (double)((int64_t)((__int128)ii * 1103515245 + 12345) & 0x7FFFFFFF) / (double)0x7FFFFFFF;
    b = (double)((int64_t)((__int128)(ii + 1) * 1103515245 + 12345) & 0x7FFFFFFF) / (double)0x7FFFFFFF;
    u = f * f * (3.0 - 2.0 * f);
    return a + (b - a) * u;
}
