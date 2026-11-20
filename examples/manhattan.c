// xylem:job xylem:math.manhattan
// xylem:function manhattan_c
// xylem:signature double(double, double, double, double)

#include <math.h>

double manhattan_c(double x1, double y1, double x2, double y2) {
    return fabs(x2 - x1) + fabs(y2 - y1);
}
