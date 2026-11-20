// xylem:job xylem:math.expo_in
// xylem:function expo_in_c
// xylem:signature double(double)

#include <math.h>

double expo_in_c(double t) {
    if (t == 0.0) {
        return 0.0;
    }
    return pow(2.0, 10.0 * (t - 1.0));
}
