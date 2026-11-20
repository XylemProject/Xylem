import math


def log1p(x):
    """Natural log of 1 plus x. Refuses values at or below -1, and non-finite values, by returning None."""
    if not math.isfinite(x) or x <= -1:
        return None
    return math.log1p(x)
