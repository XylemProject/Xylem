// xylem:job xylem:math.tan_deg
// xylem:function tan_deg_c
// xylem:signature double(double)

#include <math.h>

double tan_deg_c(double d) {
    double r = fmod(d, 180.0);
    if (r < 0.0) { r += 180.0; }
    if (r == 90.0) { return NAN; }
    return tan(d * (acos(-1.0) / 180.0));
}
