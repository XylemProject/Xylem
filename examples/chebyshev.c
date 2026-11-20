// xylem:job xylem:math.chebyshev
// xylem:function chebyshev_c
// xylem:signature double(double, double, double, double)

#include <math.h>

double chebyshev_c(double x1, double y1, double x2, double y2) {
    double dx = fabs(x2 - x1);
    double dy = fabs(y2 - y1);
    return dx > dy ? dx : dy;
}
