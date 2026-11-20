// xylem:job xylem:math.sign
// xylem:function sign_c

int sign_c(int value) {
    if (value < 0) {
        return -1;
    }
    if (value > 0) {
        return 1;
    }
    return 0;
}
