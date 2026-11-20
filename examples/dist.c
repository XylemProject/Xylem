// xylem:job xylem:math.dist
// xylem:function dist_c
// xylem:signature double(double, double, double, double)

#include <math.h>

double dist_c(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1);
}
