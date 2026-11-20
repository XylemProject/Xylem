// xylem:job xylem:math.trunc
// xylem:function trunc_c
// xylem:signature double(double)

#include <math.h>

double trunc_c(double x) {
    if (!isfinite(x)) { return NAN; }
    return trunc(x);
}
