// xylem:job xylem:math.triangle
// xylem:function triangle_c
// xylem:signature double(double)

#include <math.h>

double triangle_c(double x) {
    double r = fmod(x, 2.0);
    if (r < 0.0) { r += 2.0; }
    return fabs(r - 1.0);
}
