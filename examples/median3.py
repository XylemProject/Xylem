def median3(x, y, z):
    """Return the median of x, y, and z."""
    if x > y:
        x, y = y, x
    if y > z:
        y, z = z, y
    if x > y:
        x, y = y, x
    return y
