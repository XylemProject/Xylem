// xylem:job xylem:math.round
// xylem:function round_c
// xylem:signature double(double)

#include <math.h>

double round_c(double x) {
    return floor(x + 0.5);
}
