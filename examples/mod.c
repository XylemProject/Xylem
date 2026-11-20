// xylem:job xylem:math.mod
// xylem:function mod_c
// xylem:signature double(double, double)

#include <math.h>

double mod_c(double x, double y) {
    double r = fmod(x, y);
    if ((r < 0.0 && y > 0.0) || (r > 0.0 && y < 0.0)) {
        r += y;
    }
    return r;
}
