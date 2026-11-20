// xylem:job xylem:physics.aabb_overlap
// xylem:function aabb_overlap_c
// xylem:signature double(double, double, double, double, double, double, double, double)

double aabb_overlap_c(double ax, double ay, double aw, double ah, double bx, double by, double bw, double bh) {
    return (ax < bx + bw && ax + aw > bx && ay < by + bh && ay + ah > by) ? 1.0 : 0.0;
}
