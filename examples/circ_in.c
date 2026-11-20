// xylem:job xylem:math.circ_in
// xylem:function circ_in_c
// xylem:signature double(double)

#include <math.h>

double circ_in_c(double t) {
    return 1.0 - sqrt(1.0 - t);
}
