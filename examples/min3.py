def min3(x, y, z):
    """Return the smallest of x, y, and z."""
    m = x if x <= y else y
    return m if m <= z else z
