// xylem:job xylem:math.pow_safe
// xylem:function pow_safe_c
// xylem:signature double(double, double)

#include <math.h>

double pow_safe_c(double base, double exponent) {
    if (base < 0.0 && exponent != floor(exponent)) {
        return 0.0;
    }
    return pow(base, exponent);
}
