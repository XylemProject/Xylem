// xylem:job xylem:math.sin_deg
// xylem:function sin_deg_c
// xylem:signature double(double)

#include <math.h>

double sin_deg_c(double d) {
    return sin(d * (acos(-1.0) / 180.0));
}
