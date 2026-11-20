// xylem:job xylem:math.exp_decay
// xylem:function exp_decay_c
// xylem:signature double(double, double, double)

#include <math.h>

double exp_decay_c(double value, double rate, double t) {
    return value * exp(-rate * t);
}
