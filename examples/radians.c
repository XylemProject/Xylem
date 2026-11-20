// xylem:job xylem:math.radians
// xylem:function radians_c
// xylem:signature double(double)

#include <math.h>

double radians_c(double d) {
    return d * (acos(-1.0) / 180.0);
}
