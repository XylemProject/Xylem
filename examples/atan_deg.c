// xylem:job xylem:math.atan_deg
// xylem:function atan_deg_c
// xylem:signature double(double)

#include <math.h>

double atan_deg_c(double x) {
    if (!isfinite(x)) { return NAN; }
    return atan(x) * (180.0 / acos(-1.0));
}
