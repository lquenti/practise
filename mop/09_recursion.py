def sequence(xn):
    return xn/2 + 1/xn

def n_with_delter_smaller_than(x1, this):
    x,y = x1, sequence(x1)
    n = 2
    while abs(y-x) >= this:
        x,y = y, sequence(y)
        n+=1
    return n,y

def find_root(f,lval,rval,tol):
    while abs(rval-lval) <= 2*tol:
        g = f((lval+rval)/2)
        if f(lval) * g <= 0:
            rval = (lval+rval)/2
        else:
            lval = (lval+rval)/2
    return (lval+rval)/2

def disk_usage(d):
    ret = 0
    for k in d:
        v = d[k]
        if isinstance(v, dict):
            ret += disk_usage(v)
        else:
            print(k, v)
            ret += v
    return ret

if __name__ == '__main__':
    # 1
    print(n_with_delter_smaller_than(10, 1e-4))
    # 2
    find_root(lambda x:x**3-2, 0,3,10e-4)
    # 3
    d = {
        'documents':{
            'erinnerung.txt':3,
            'skripte':{
                'matheskript.pdf':15,
                'pythontutorial.pdf':22}
            },
        'selfie.jpg':100
    }
    print(disk_usage(d))
