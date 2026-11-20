// xylem:job xylem:math.quantize
// xylem:function quantize_c
// xylem:signature double(double, double)

#include <math.h>

double quantize_c(double x, double step) {
    return floor(x / step) * step;
}
