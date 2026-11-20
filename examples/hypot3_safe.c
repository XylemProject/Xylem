// xylem:job xylem:math.hypot3_safe
// xylem:function hypot3_safe_c
// xylem:signature double(double, double, double)

#include <math.h>

double hypot3_safe_c(double a, double b, double c) {
    if (!isfinite(a) || !isfinite(b) || !isfinite(c)) {
        return NAN;
    }
    return sqrt(a * a + b * b + c * c);
}
