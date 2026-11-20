// xylem:job xylem:math.deg_norm
// xylem:function deg_norm_c
// xylem:signature double(double)

#include <math.h>

double deg_norm_c(double d) {
    double r = fmod(d, 360.0);
    if (r < 0.0) { r += 360.0; }
    return r;
}
