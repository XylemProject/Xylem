// xylem:job xylem:math.remap_unclamped
// xylem:function remap_unclamped_c
// xylem:signature double(double, double, double, double, double)

#include <math.h>

double remap_unclamped_c(double x, double in_min, double in_max, double out_min, double out_max) {
    if (in_min == in_max) {
        return NAN;
    }
    return out_min + (out_max - out_min) * (x - in_min) / (in_max - in_min);
}
