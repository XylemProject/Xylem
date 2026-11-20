// xylem:job xylem:math.saw_wave_safe
// xylem:function saw_wave_safe_c
// xylem:signature double(double)

#include <math.h>

double saw_wave_safe_c(double x) {
    if (!isfinite(x)) {
        return NAN;
    }
    return x - floor(x);
}
