// xylem:job xylem:math.min_value
// xylem:function min_value_c

int min_value_c(int left, int right) {
    if (left < right) {
        return left;
    }
    return right;
}
