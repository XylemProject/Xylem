// xylem:job xylem:math.ceil_to
// xylem:function ceil_to_c
// xylem:signature double(double, double)

#include <math.h>

double ceil_to_c(double x, double step) {
    return floor((x + step - 1.0) / step) * step;
}
