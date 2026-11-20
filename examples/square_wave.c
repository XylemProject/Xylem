// xylem:job xylem:math.square_wave
// xylem:function square_wave_c
// xylem:signature double(double)

#include <math.h>

double square_wave_c(double x) {
    double r = fmod(x, 2.0);
    if (r < 0.0) { r += 2.0; }
    return r < 1.0 ? 1.0 : 0.0;
}
