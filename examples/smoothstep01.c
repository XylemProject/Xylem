// xylem:job xylem:math.smoothstep01
// xylem:function smoothstep01_c
// xylem:signature double(double)

double smoothstep01_c(double t) {
    return t * t * (3.0 - 2.0 * t);
}
