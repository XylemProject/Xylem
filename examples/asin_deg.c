// xylem:job xylem:math.asin_deg
// xylem:function asin_deg_c
// xylem:signature double(double)

#include <math.h>

double asin_deg_c(double x) {
    if (x < -1.0 || x > 1.0) { return NAN; }
    return asin(x) * (180.0 / acos(-1.0));
}
