import numpy as np
from scipy.linalg import hilbert

def np_mean(xs):
    return np.sum(xs)/np.size(xs)

mat = np.diag(np.ones(100)*2) + np.diag(np.ones(99)*-1, k=1) + np.diag(np.ones(99)*-1,k=-1)

hil = hilbert(50)

rnd = np.random.randint(0,10,(2,3,4,5))

if __name__ == '__main__':
    #2
    print(mat)
    #3
    print(np.sum(hil[:, 2]))
    #4
    print(np.sum(rnd, axis=(2,3)))
    #5
