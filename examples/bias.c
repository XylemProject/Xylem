// xylem:job xylem:math.bias
// xylem:function bias_c
// xylem:signature double(double, double)

#include <math.h>

double bias_c(double x, double bias) {
    return pow(x, log(bias) / log(0.5));
}
