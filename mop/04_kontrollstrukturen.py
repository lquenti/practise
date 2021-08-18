from numpy.random import random
# Aufgabe 1
def sq(i):
    return i*i
def delta(i,j):
    return abs(i-j)
l = [delta(i, sq(i)) for i in range(1,11)]

# Aufgabe 2
def sum2(xs):
    ret=0
    for i in xs:
        ret+=i
    return ret
# Aufgabe 3
l = [i for i in range(1000) if i%2 == i%3 == i%7 == 0]
print(len(l))
# Aufgabe 4
def fizzbuzz(n):
    ret = []
    for i in range(1,n):
        v = ''
        if i%3==0:
            v+= 'fizz'
        if i%5==0:
            v+= 'buzz'
        ret.append(i if v == '' else v)
    return ret
print(fizzbuzz(100))
# Aufgabe 5
is_prime = lambda n: all([n % i != 0 for i in range(2,int(n**0.5)+1)])
print([i for i in range(2,100) if is_prime(i)])
# Aufgabe 6
def approx_pi(n=int(1e6)):
    return 4*sum([1 for (i,j) in [(random()*2-1, random()*2-1) for _ in range(n)] if i**2+j**2 <= 1])/n
print(approx_pi())
# Aufgabe 7
def t2d(ts):
    return {k:v for (k,v) in ts}
# Aufgabe 8
def collatz(x):
    res = [x]
    while x != 1:
        x = x//2 if not x%2 else 3*x+1
        res.append(x)
    return res
print(max([(i, len(collatz(i))) for i in range(1,501)], key=lambda x:x[1]))
# Aufgabe 9
print([(m, len([n for n in range(1,101) if is_prime(n**2+m+m**2)])) for m in range(40)])
# Aufgabe 10
def number_of_divisors(i):
    return len([j for j in range(1,i+1) if i%j==0])
# i didnt understood the second part of the exercise description so i looked at the solution Q_Q
