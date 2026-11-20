// xylem:job xylem:math.log
// xylem:function log_c
// xylem:signature double(double)

#include <math.h>

double log_c(double x) {
    if (x <= 0.0) {
        return NAN;
    }
    return log(x);
}
