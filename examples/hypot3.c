// xylem:job xylem:math.hypot3
// xylem:function hypot3_c
// xylem:signature double(double, double, double)

#include <math.h>

double hypot3_c(double a, double b, double c) {
    return sqrt(a * a + b * b + c * c);
}
