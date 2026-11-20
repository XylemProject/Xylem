// xylem:job xylem:math.pulse_wave
// xylem:function pulse_wave_c
// xylem:signature double(double, double)

#include <math.h>

double pulse_wave_c(double x, double duty) {
    if (duty <= 0.0 || duty >= 1.0) {
        return NAN;
    }
    double r = fmod(x, 1.0);
    if (r < 0.0) { r += 1.0; }
    return r < duty ? 1.0 : 0.0;
}
