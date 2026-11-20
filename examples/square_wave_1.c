// xylem:job xylem:math.square_wave_1
// xylem:function square_wave_1_c
// xylem:signature double(double)

#include <math.h>

double square_wave_1_c(double x) {
    double r = fmod(x, 1.0);
    if (r < 0.0) { r += 1.0; }
    return r < 0.5 ? 1.0 : 0.0;
}
