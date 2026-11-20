// xylem:job xylem:math.lerp
// xylem:function lerp_c
// xylem:signature double(double, double, double)

double lerp_c(double start, double end, double t) {
    return start + (end - start) * t;
}
