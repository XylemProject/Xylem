// xylem:job xylem:math.saw_wave
// xylem:function saw_wave_c
// xylem:signature double(double)

#include <math.h>

double saw_wave_c(double x) {
    return x - floor(x);
}
