// xylem:job xylem:math.saturate
// xylem:function saturate_c
// xylem:signature double(double)

double saturate_c(double value) {
    if (value < 0.0) { return 0.0; }
    if (value > 1.0) { return 1.0; }
    return value;
}
