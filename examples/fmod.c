// xylem:job xylem:math.fmod
// xylem:function fmod_c
// xylem:signature double(double, double)

#include <math.h>

double fmod_c(double x, double y) {
    if (!isfinite(x) || !isfinite(y) || y == 0.0) { return NAN; }
    return fmod(x, y);
}
