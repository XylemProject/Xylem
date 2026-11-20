// xylem:job xylem:math.smootherstep01
// xylem:function smootherstep01_c
// xylem:signature double(double)

double smootherstep01_c(double t) {
    return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}
