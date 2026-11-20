// xylem:job xylem:math.noise1
// xylem:function noise1_c
// xylem:signature double(double)

#include <math.h>
#include <stdint.h>

double noise1_c(double x) {
    double i = floor(x);
    double f = x - i;
    int64_t ii = (int64_t)i;
    int64_t a_raw = (ii * 1103515245LL + 12345LL) & 0x7FFFFFFFLL;
    int64_t b_raw = ((ii + 1) * 1103515245LL + 12345LL) & 0x7FFFFFFFLL;
    double a = (double)a_raw / (double)0x7FFFFFFF;
    double b = (double)b_raw / (double)0x7FFFFFFF;
    double u = f * f * (3.0 - 2.0 * f);
    return a + (b - a) * u;
}
