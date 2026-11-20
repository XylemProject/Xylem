// xylem:job xylem:math.circ_in_out
// xylem:function circ_in_out_c
// xylem:signature double(double)

#include <math.h>

double circ_in_out_c(double t) {
    if (t < 0.5) {
        return 0.5 * (1.0 - sqrt(1.0 - 2.0 * t));
    }
    return 0.5 * (sqrt(2.0 * t - 1.0) + 1.0);
}
