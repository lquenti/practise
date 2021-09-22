def intervalsplit(f,a,b):
    while True:
        c = (a+b)/2
        fc = f(c)
        fb = f(b)
        if (fb < 0) == (fc < 0):
            a,b = a,c
        else:
            a,b = c,b
        yield (a,b)

def list_to_dict(xs):
    ret = dict()
    for x in xs:
        if x not in ret:
            ret[x] = 1
        else:
            ret[x] = ret[x] + 1
    return ret

if __name__ == '__main__':
    # 1
    for a,b in intervalsplit(lambda x: x**2 - 2,1,2):
        print(a,b)
        if abs(b-a) < 1e-4:
            break

