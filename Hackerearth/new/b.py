import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


import math as mt
N = int(1e6+5)


def sieve():
    spf[1] = 1
    for i in range(2, N):
        spf[i] = i

    for i in range(4, N, 2):
        spf[i] = 2

    for i in range(3, mt.ceil(mt.sqrt(N))):
        if (spf[i] == i):
            for j in range(i * i, N, i):

                if (spf[j] == j):
                    spf[j] = i


def getFactorization(x):
    ret = list()
    while (x != 1):
        ret.append(spf[x])
        x = x // spf[x]
    return ret


def main():
    global spf
    spf = [0]*(N)
    sieve()
    x, n = get_ints()
    arr = get_array()
    count = [0]*n
    for i in range(n):
        x = arr[i]
        count[i] = len(getFactorization(x))
    print(count)


if __name__ == "__main__":
    main()
