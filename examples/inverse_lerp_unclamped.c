// xylem:job xylem:math.inverse_lerp_unclamped
// xylem:function inverse_lerp_unclamped_c
// xylem:signature double(double, double, double)

#include <math.h>

double inverse_lerp_unclamped_c(double a, double b, double x) {
    if (a == b) {
        return NAN;
    }
    return (x - a) / (b - a);
}
