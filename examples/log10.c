// xylem:job xylem:math.log10
// xylem:function log10_c
// xylem:signature double(double)

#include <math.h>

double log10_c(double x) {
    if (x <= 0.0) {
        return NAN;
    }
    return log10(x);
}
