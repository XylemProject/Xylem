// xylem:job xylem:math.log2
// xylem:function log2_c
// xylem:signature double(double)

#include <math.h>

double log2_c(double x) {
    if (x <= 0.0) {
        return NAN;
    }
    return log2(x);
}
