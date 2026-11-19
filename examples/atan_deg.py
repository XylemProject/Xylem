import math


def atan_deg(x):
    """Arctangent returning degrees. Refuses non-finite values by returning None."""
    if not math.isfinite(x):
        return None
    return math.degrees(math.atan(x))
