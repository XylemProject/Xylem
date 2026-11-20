// xylem:job xylem:math.sinc
// xylem:function sinc_c
// xylem:signature double(double)

#include <math.h>

double sinc_c(double x) {
    if (!isfinite(x)) { return NAN; }
    if (x == 0.0) { return 1.0; }
    return sin(x) / x;
}
