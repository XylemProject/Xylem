// xylem:job xylem:math.hash01
// xylem:function hash01_c
// xylem:signature double(double)

#include <math.h>

double hash01_c(double x) {
    double r = fmod(x * 0.1031, 1.0);
    if (r < 0.0) {
        r += 1.0;
    }
    return fabs(r);
}
