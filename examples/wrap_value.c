// xylem:job xylem:math.wrap_value
// xylem:function wrap_value_c
// xylem:signature double(double, double, double)

#include <math.h>

double wrap_value_c(double value, double low, double high) {
    double span = high - low;
    if (span == 0.0) {
        return low;
    }
    double offset = value - low;
    double r = fmod(offset, span);
    if ((r < 0.0 && span > 0.0) || (r > 0.0 && span < 0.0)) {
        r += span;
    }
    return low + r;
}
