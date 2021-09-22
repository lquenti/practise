#   4 * (\pi * r^2) / ((2*r)^2)
# = 4*(\pi * r^2) / (4 * r^2)
# = \pi

import itertools as it
import numpy as np

def pi_approx_monte_carlo_integration():
    num, denom = 0,0
    while True:
        x,y = np.random.random()*2-1, np.random.random()*2-1
        denom+=1
        if x**2 + y**2 < 1:
            num+=1
        print(num, denom)
        yield 4*num/denom

def every_nth_itertools(it, n):
    for m,x in zip(it.cycle(range(n)), it):
        if n == m:
            return x

def every_nth_loop(it, n):
    m = n
    for x in it:
        m-=1
        if m == 0:
            yield x
            m = n

if __name__ == '__main__':
    # 1
    xs = [*
        it.takewhile(lambda x: abs(x-np.pi)>=0.001,
        pi_approx_monte_carlo_integration())
    ]
    for x in xs:
        print(x)
