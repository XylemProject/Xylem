// xylem:job xylem:math.wrap_degrees
// xylem:function wrap_degrees_c
// xylem:signature double(double)

#include <math.h>

double wrap_degrees_c(double d) {
    double r = fmod(d + 180.0, 360.0);
    if (r < 0.0) { r += 360.0; }
    return r - 180.0;
}
