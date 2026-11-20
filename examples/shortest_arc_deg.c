// xylem:job xylem:math.shortest_arc_deg
// xylem:function shortest_arc_deg_c
// xylem:signature double(double, double)

#include <math.h>

static double euclid_mod(double x, double period) {
    double r = fmod(x, period);
    if ((r < 0.0 && period > 0.0) || (r > 0.0 && period < 0.0)) {
        r += period;
    }
    return r;
}

double shortest_arc_deg_c(double a, double b) {
    const double turn = 360.0;
    double d = euclid_mod(b - a, turn);
    if (d > 180.0) {
        d -= turn;
    }
    return d;
}
