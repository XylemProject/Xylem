// xylem:job xylem:math.acos_deg
// xylem:function acos_deg_c
// xylem:signature double(double)

#include <math.h>

double acos_deg_c(double x) {
    if (x < -1.0 || x > 1.0) { return NAN; }
    return acos(x) * (180.0 / acos(-1.0));
}
