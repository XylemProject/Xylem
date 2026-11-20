// xylem:job xylem:math.even
// xylem:function even_c
// xylem:signature double(double)

#include <math.h>

double even_c(double x) {
    double r = fmod(x, 2.0);
    if (r < 0.0) {
        r += 2.0;
    }
    return (r == 0.0) ? 1.0 : 0.0;
}
