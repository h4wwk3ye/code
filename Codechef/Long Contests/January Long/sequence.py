#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <13/Jan/2019 12:40:18 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#   https://www.codechef.com/JAN19A/problems/EARTSEQ
#

# ///==========Libraries, Constants and Functions=============///


import sys


inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def primes_sieve(limit):
    a = [True] * limit                       # Initialize the primality list
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime == True:
            yield i
            for n in range(i * i, limit, i):     # Mark factors non-prime
                a[n] = False


def precompute():
    d = {}
    ans[0] = 6
    ans[1] = 10
    from collections import defaultdict
    check = defaultdict(dict)
    check[0][1] = 1
    check[0][2] = 1  # 2
    check[1][0] = 1  # 3
    check[2][0] = 1  # 5
    prev = 2  # 5
    mx = 2
    m = 11

    for i in range(2, 50005):
        key = -1
        if prev == 0:
            key = mx + 1
            mx += 1
        elif prev == 1:
            key = m + 1
            m += 1
        else:
            for j in range(2):
                if j != prev and j not in check[prev]:
                    # print(j, prev)
                    key = j
                    if key == 0:
                        mx = prev
                    elif key == 1:
                        m = prev
                    break
        ans[i] = primes[prev] * primes[key]
        check[prev][key] = 1
        check[key][prev] = 1
        prev = key


def primeFactors(n):
    import math
    factors = []
    while n % 2 == 0:
        factors.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):

        while n % i == 0:
            factors.append(i)
            n = n // i

    if n > 2:
        factors.append(n)
    return factors


def main():
    precompute()
    arr = ans
    from math import gcd
    #import random
    for tc in range(int(input())):
        n = int(input())
        if n == 3:
            print(6, 10, 15)
            continue

        if n % 2 == 1:
            # print(*arr[:n])
            p, q = primeFactors(arr[n - 1])
            if p > q:
                p, q = q, p
            r, s = primeFactors(arr[n - 2])
            if r > s:
                r, s = s, r
            if p == r:
                common = p
                other = q
            elif q == s:
                common = q
                other = p
            if p == 7 or q == 7:
                x = (arr[n - 1] // other) * 11
                y = (arr[0]) * 11
            else:
                x = (arr[n - 1] // other) * 7
                y = arr[0] * 7

            l = [y] + arr[1:n - 1] + [x]
            print(*l)
            '''for i in range(n):
                if l[i] > 10**9 or gcd(l[i], l[(i + 1) % n]) == 1:
                    print(i, 1, l[i], l[(i + 1) % n])
                    print('no')
                    break
                if gcd(l[i], gcd(l[(i + 1) % n], l[(i + 2) % n])) != 1:
                    print(i, 2)
                    print('no')
                    sys.exit()
            # print('yes')'''
        else:
            p, q = primeFactors(arr[n - 1])
            if p > q:
                p, q = q, p
            r, s = primeFactors(arr[n - 2])
            if r > s:
                r, s = s, r
            common = p
            if common == 3:
                x = 3 * 7 * 3
                y = (arr[0] // 3) * 7 * 2
                l = [y] + arr[1:n - 1] + [x]
                print(*l)
                '''for i in range(n):
                    if l[i] > 10**9 or gcd(l[i], l[(i + 1) % n]) == 1:
                        print(i, 1, l[i], l[(i + 1) % n])
                        print('no')
                        break
                    if gcd(l[i], gcd(l[(i + 1) % n], l[(i + 2) % n])) != 1:
                        print(i, 2)
                        print('no')
                        sys.exit()
                # print('yes')'''
            else:
                if s == 7:
                    u = s * 11
                    v = 11 * 13
                    y = arr[0] * 13
                else:
                    u = s * 7
                    v = 7 * 11
                    y = arr[0] * 11
                l = [y] + arr[1:n - 2] + [u] + [v]
                print(*l)
                '''for i in range(n):
                    if l[i] > 10**9 or gcd(l[i], l[(i + 1) % n]) == 1:
                        print(i, 1, l[i], l[(i + 1) % n])
                        print('no')
                        sys.exit()
                    if gcd(l[i], gcd(l[(i + 1) % n], l[(i + 2) % n])) != 1:
                        print(i, 2)
                        print('no')
                        sys.exit()'''


if __name__ == "__main__":
    primes = list(primes_sieve(1000001))
    # print(len(primes))
    ans = [0] * 50005
    main()
