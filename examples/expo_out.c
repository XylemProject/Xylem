// xylem:job xylem:math.expo_out
// xylem:function expo_out_c
// xylem:signature double(double)

#include <math.h>

double expo_out_c(double t) {
    if (t == 1.0) {
        return 1.0;
    }
    return 1.0 - pow(2.0, -10.0 * t);
}
