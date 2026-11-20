// xylem:job xylem:math.gain
// xylem:function gain_c
// xylem:signature double(double)

#include <math.h>

double gain_c(double x) {
    if (x < 0.5) {
        return 0.5 * sqrt(2.0 * x);
    }
    return 1.0 - 0.5 * sqrt(2.0 * (1.0 - x));
}
