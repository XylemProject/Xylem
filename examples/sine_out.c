// xylem:job xylem:math.sine_out
// xylem:function sine_out_c
// xylem:signature double(double)

#include <math.h>

double sine_out_c(double t) {
    return sin(t * acos(-1.0) / 2.0);
}
