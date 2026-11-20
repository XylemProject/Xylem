// xylem:job xylem:math.floor_to
// xylem:function floor_to_c
// xylem:signature double(double, double)

#include <math.h>

double floor_to_c(double x, double step) {
    return floor(x / step) * step;
}
