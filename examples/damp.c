// xylem:job xylem:math.damp
// xylem:function damp_c
// xylem:signature double(double, double, double, double)

#include <math.h>

double damp_c(double current, double target, double rate, double dt) {
    return current + (target - current) * (1.0 - exp(-rate * dt));
}
