// xylem:job xylem:math.hypot_deg
// xylem:function hypot_deg_c
// xylem:signature double(double, double)

#include <math.h>

double hypot_deg_c(double a, double b) {
    const double rad2deg = 180.0 / 3.14159265358979323846;
    double h = hypot(a, b);
    if (h == 0.0) {
        return NAN;
    }
    return asin(a / h) * rad2deg;
}
