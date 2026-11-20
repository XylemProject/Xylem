import math


def approx_equal(x, y, eps):
    """Return True if x and y differ by at most eps. Refuses non-finite values or a negative eps by returning None."""
    if not (math.isfinite(x) and math.isfinite(y) and math.isfinite(eps)) or eps < 0:
        return None
    return abs(x - y) <= eps
