// xylem:job xylem:math.triangle_wave
// xylem:function triangle_wave_c
// xylem:signature double(double)

#include <math.h>

double triangle_wave_c(double x) {
    double r = fmod(x, 1.0);
    if (r < 0.0) { r += 1.0; }
    return 1.0 - fabs(2.0 * r - 1.0);
}
