// xylem:job xylem:math.degrees
// xylem:function degrees_c
// xylem:signature double(double)

#include <math.h>

double degrees_c(double r) {
    return r * (180.0 / acos(-1.0));
}
