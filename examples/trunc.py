import math


def trunc(x):
    """Return the integer part of x, toward zero. Refuses non-finite values by returning None."""
    if not math.isfinite(x):
        return None
    if x >= 0:
        return x // 1
    return -((-x) // 1)
