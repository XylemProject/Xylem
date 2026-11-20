// xylem:job xylem:math.fract
// xylem:function fract_c
// xylem:signature double(double)

#include <math.h>

double fract_c(double x) {
    return x - floor(x);
}
