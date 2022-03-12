#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <20/Feb/2019 11:03:37 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


cubes = []


def cbrt(n):
    return int(pow(n, 1/3))


def precompute():
    global cubes
    a = cbrt(1)
    b = cbrt(1e15)
    for i in range(a, b+1):
        x = i*i*i
        if x >= a and x <= b:
            cubes.append(x)


def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


def main():
    precompute()
    # print(cubes)
    n = int(input())
    no = [1]*n
    for i in range(n):
        x = get_array()
        for j in range(x[0]):
            no[i] *= x[j+1]
    ans = 0
    import bisect
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                for l in range(k+1, n):
                    m = no[i]*no[j]*no[k]*no[l]
                    ind = bisect.bisect_left(cubes, m)
                    if (cubes[ind] == m):
                        ans += 1

    print(ans)


if __name__ == "__main__":
    main()
