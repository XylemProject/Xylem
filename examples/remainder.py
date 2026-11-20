import math


def remainder(x, y):
    """IEEE remainder of x divided by y, using the nearest integer quotient. Refuses a zero divisor or non-finite values by returning None."""
    if not (math.isfinite(x) and math.isfinite(y)) or y == 0:
        return None
    return math.remainder(x, y)
