// xylem:job xylem:math.noise01
// xylem:function noise01_c
// xylem:signature double(double)

#include <math.h>

double noise01_c(double x) {
    double r = fmod(x * 12.9898, 1.0);
    if (r < 0.0) {
        r += 1.0;
    }
    return fabs(r);
}
