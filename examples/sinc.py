import math


def sinc(x):
    """sin(x) divided by x, with sinc(0) equal to 1. Refuses non-finite values by returning None."""
    if not math.isfinite(x):
        return None
    if x == 0:
        return 1.0
    return math.sin(x) / x
