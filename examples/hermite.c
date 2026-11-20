// xylem:job xylem:math.hermite
// xylem:function hermite_c
// xylem:signature double(double)

double hermite_c(double t) {
    return t * t * (3.0 - 2.0 * t);
}
