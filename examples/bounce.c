// xylem:job xylem:math.bounce
// xylem:function bounce_c
// xylem:signature double(double)

#include <math.h>

double bounce_c(double x) {
    double r = fmod(x, 2.0);
    if (r < 0.0) { r += 2.0; }
    return 1.0 - fabs(r - 1.0);
}
