// xylem:job xylem:math.saw
// xylem:function saw_c
// xylem:signature double(double)

#include <math.h>

double saw_c(double x) {
    double r = fmod(x, 1.0);
    if (r < 0.0) { r += 1.0; }
    return r;
}
