// xylem:job xylem:math.expo_in_out
// xylem:function expo_in_out_c
// xylem:signature double(double)

#include <math.h>

double expo_in_out_c(double t) {
    if (t == 0.0) {
        return 0.0;
    }
    if (t == 1.0) {
        return 1.0;
    }
    if (t < 0.5) {
        return 0.5 * pow(2.0, 20.0 * t - 10.0);
    }
    return 1.0 - 0.5 * pow(2.0, -20.0 * t + 10.0);
}
