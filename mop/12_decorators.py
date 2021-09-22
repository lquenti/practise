import time

def time_dec(f):
    def wrap(*args, **kwargs):
        b4 = time.perf_counter()
        ret = f(*args,**kwargs)
        after = time.perf_counter()
        print(after-b4)
        return ret
    return wrap

def rec(x,n):
    return x**(n//2)*x**(n//2) if n%2==0 else x*x**((n-1)//2)*x**((n-1)//2)

def count_rec(f):
    cnt = 0
    def wrap(*args, **kwargs):
        nonlocal cnt
        print(f"depth: {cnt}")
        cnt += 1
        res = f(*args,**kwargs)
        cnt -= 1
        return res
    return wrap

def my_cache(f):
    func_lookups = dict()
    def wrap(*args):
        if f not in func_lookups:
            func_lookups[f] = dict()
        all_args = tuple(args)
        if all_args not in func_lookups[f]:
            func_lookups[f][all_args] = f(*args)
        return func_lookups[f][all_args]
    return wrap
