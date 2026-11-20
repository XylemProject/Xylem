// xylem:job xylem:math.smooth_max
// xylem:function smooth_max_c
// xylem:signature double(double, double, double)

#include <math.h>

double smooth_max_c(double a, double b, double k) {
    if (k <= 0.0) {
        return fmax(a, b);
    }
    double h = fmax(k - fabs(a - b), 0.0) / k;
    return fmax(a, b) + h * h * k * 0.25;
}
