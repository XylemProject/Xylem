// xylem:job xylem:math.cbrt
// xylem:function cbrt_c
// xylem:signature double(double)

#include <math.h>

double cbrt_c(double x) {
    return copysign(pow(fabs(x), 1.0 / 3.0), x);
}
