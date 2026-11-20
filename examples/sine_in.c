// xylem:job xylem:math.sine_in
// xylem:function sine_in_c
// xylem:signature double(double)

#include <math.h>

double sine_in_c(double t) {
    return 1.0 - cos(t * acos(-1.0) / 2.0);
}
