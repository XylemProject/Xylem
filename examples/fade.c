// xylem:job xylem:math.fade
// xylem:function fade_c
// xylem:signature double(double)

double fade_c(double t) {
    return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}
