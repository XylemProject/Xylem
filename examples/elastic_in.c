// xylem:job xylem:math.elastic_in
// xylem:function elastic_in_c
// xylem:signature double(double)

#include <math.h>

double elastic_in_c(double t) {
    if (t == 0.0) {
        return 0.0;
    }
    if (t == 1.0) {
        return 1.0;
    }
    return -pow(2.0, 10.0 * t - 10.0) * sqrt(t * 10.0 - 10.75);
}
