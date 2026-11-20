// xylem:job xylem:math.mix
// xylem:function mix_c
// xylem:signature double(double, double, double)

double mix_c(double a, double b, double t) {
    return a + (b - a) * t;
}
