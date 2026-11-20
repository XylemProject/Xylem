// xylem:job xylem:math.smooth_min
// xylem:function smooth_min_c
// xylem:signature double(double, double, double)

#include <math.h>

double smooth_min_c(double a, double b, double k) {
    if (k <= 0.0) {
        return fmin(a, b);
    }
    double h = fmax(k - fabs(a - b), 0.0) / k;
    return fmin(a, b) - h * h * k * 0.25;
}
