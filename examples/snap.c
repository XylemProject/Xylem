// xylem:job xylem:math.snap
// xylem:function snap_c
// xylem:signature double(double, double)

#include <math.h>

double snap_c(double x, double step) {
    return floor((x + step / 2.0) / step) * step;
}
