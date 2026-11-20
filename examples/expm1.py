import math


def expm1(x):
    """e raised to x, minus one. Refuses non-finite values by returning None."""
    if not math.isfinite(x):
        return None
    return math.expm1(x)
