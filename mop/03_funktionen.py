from math import sqrt

# Aufgabe 1
def head(xs):
    return xs[0]

def tail(xs):
    return xs[1:]

# Aufgabe 2
def inc(i, by=1):
    return i+by

# Aufgabe 3
def givemefive(xs, begin=0):
    return xs[begin:begin+5]

# Aufgabe 4
def betrag(z):
    return sqrt(z.real**2 + z.imag**2)
