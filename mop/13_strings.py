def count(c,xs):
    ret = 0
    for x in xs:
        if x == c:
            ret +=1
    return ret

def invert(xs):
    return xs[::-1]
