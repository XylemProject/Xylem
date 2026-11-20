// xylem:job xylem:math.round_to
// xylem:function round_to_c
// xylem:signature double(double, double)

#include <math.h>

double round_to_c(double x, double step) {
    return floor((x + step / 2.0) / step) * step;
}
