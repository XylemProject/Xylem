// xylem:job xylem:math.atan2_deg
// xylem:function atan2_deg_c
// xylem:signature double(double, double)

#include <math.h>

double atan2_deg_c(double y, double x) {
    double r = atan2(y, x) * (180.0 / acos(-1.0));
    if (r <= -180.0) { r += 360.0; }
    return r;
}
