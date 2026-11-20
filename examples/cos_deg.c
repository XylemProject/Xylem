// xylem:job xylem:math.cos_deg
// xylem:function cos_deg_c
// xylem:signature double(double)

#include <math.h>

double cos_deg_c(double d) {
    return cos(d * (acos(-1.0) / 180.0));
}
