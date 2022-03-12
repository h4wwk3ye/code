#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <20/Feb/2019 05:54:26 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(10**6)
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///

'''
def multiply(F, M):
    x = (((F[0][0]*M[0][0]) % mod) + ((F[0][1]*M[1][0]) % mod)) % mod
    y = (((F[0][0]*M[0][1]) % mod) + ((F[0][1]*M[1][1]) % mod)) % mod
    z = (((F[1][0]*M[0][0]) % mod) + ((F[1][1]*M[1][0]) % mod)) % mod
    w = (((F[1][0]*M[0][1]) % mod) + ((F[1][1]*M[1][1]) % mod)) % mod

    F[0][0] = x
    F[0][1] = y
    F[1][0] = z
    F[1][1] = w


def power(matrix, n):
    if n == 0 or n == 1:
        return
    res = [[1, 1], [1, 0]]
    power(matrix, n//2)
    multiply(matrix, matrix)
    if n & 1:
        multiply(matrix, res)


def fib(n):
    matrix = [[1, 1], [1, 0]]
    if n == 0:
        return 0
    power(matrix, n-1)
    return matrix[0][0]
'''

import math

sqrt_five = math.sqrt(5)
Phi = (1 + sqrt_five)/2


def fib(num):
    return int(((pow(Phi, num, mod))-(pow(-Phi, -num, mod)))/sqrt_five)


def main():
    '''from itertools import permutations, combinations
    n = int(input())
    arr = [i+1 for i in range(n)]
    p = []
    for i in permutations(arr):
        p.append(i)
    # print(p)
    s = []
    for i in range(n+1):
        x = combinations(arr, i)
        for j in x:
            s.append(j)
    # print(s)
    ans = 0
    for k in s:
        for i in p:
            for j in range(n):
                if (j+1 in k and i[j] in k):
                    ans += 1
                    break
    from math import gcd, factorial
    d = factorial(n)
    while gcd(d, ans) != 1:
        u = gcd(d, ans)
        d //= u
        ans //= u
    print(ans, d)

    numerator== 2**n-fib(n)'''
    for tc in range(int(input())):
        n = int(input())
        y = pow(2, n, mod)
        x = y-fib(n+1)
        # print(fib(n+1))
        print(x, y)
        print(((x % mod) * pow(y, mod - 2, mod)) % mod)


if __name__ == "__main__":
    main()
