// xylem:job xylem:math.approach
// xylem:function approach_c
// xylem:signature double(double, double, double)

double approach_c(double current, double target, double step) {
    if (step < 0.0) {
        step = -step;
    }
    if (current < target) {
        double next_value = current + step;
        if (next_value > target) {
            return target;
        }
        return next_value;
    }
    {
        double next_value = current - step;
        if (next_value < target) {
            return target;
        }
        return next_value;
    }
}
