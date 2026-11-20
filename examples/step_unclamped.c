// xylem:job xylem:math.step_unclamped
// xylem:function step_unclamped_c
// xylem:signature double(double, double, double)

#include <math.h>

double step_unclamped_c(double edge, double x, double width) {
    if (width <= 0.0) {
        return NAN;
    }
    return (x - edge) / width + 0.5;
}
