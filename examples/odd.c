// xylem:job xylem:math.odd
// xylem:function odd_c
// xylem:signature int(double)
// xylem:returns optional_bool

#include <math.h>

int odd_c(double x) {
    double r = fmod(x, 2.0);
    if (r < 0.0) {
        r += 2.0;
    }
    return (r != 0.0) ? 1 : 0;
}
