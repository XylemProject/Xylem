import math


def copysign(x, y):
    """Return the magnitude of x with the sign of y. Zero y is treated as positive. Refuses non-finite input by returning None."""
    if not (math.isfinite(x) and math.isfinite(y)):
        return None
    if y < 0:
        return -abs(x)
    return abs(x)
