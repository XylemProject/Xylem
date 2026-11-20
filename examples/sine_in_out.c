// xylem:job xylem:math.sine_in_out
// xylem:function sine_in_out_c
// xylem:signature double(double)

#include <math.h>

double sine_in_out_c(double t) {
    return 0.5 * (1.0 - cos(acos(-1.0) * t));
}
