def max3(x, y, z):
    """Return the largest of x, y, and z."""
    m = x if x >= y else y
    return m if m >= z else z
