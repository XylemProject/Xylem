// xylem:job xylem:math.wrap_180
// xylem:function wrap_180_c
// xylem:signature double(double)

#include <math.h>

double wrap_180_c(double d) {
    double r = fmod(d, 360.0);
    if (r < 0.0) { r += 360.0; }
    if (r > 180.0) { r -= 360.0; }
    return r;
}
