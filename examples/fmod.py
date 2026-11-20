import math


def fmod(x, y):
    """Remainder of x divided by y, with the sign of x. Refuses a zero divisor or non-finite values by returning None."""
    if not (math.isfinite(x) and math.isfinite(y)) or y == 0:
        return None
    return math.fmod(x, y)
