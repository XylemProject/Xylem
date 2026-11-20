// xylem:job xylem:math.elastic_out
// xylem:function elastic_out_c
// xylem:signature double(double)

#include <math.h>

double elastic_out_c(double t) {
    if (t == 0.0) {
        return 0.0;
    }
    if (t == 1.0) {
        return 1.0;
    }
    return pow(2.0, -10.0 * t) * sqrt(t * 10.0 - 0.75) + 1.0;
}
