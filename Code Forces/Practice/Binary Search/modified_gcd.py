#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <27/Mar/2019 07:27:55 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    a, b = get_ints()
    from math import gcd, sqrt
    x = gcd(a, b)
    divisors = []
    i = 1
    while i <= sqrt(x):
        if (x % i == 0):
            if (x//i == i):
                divisors.append(i)
            else:
                divisors.append(i)
                divisors.append(x//i)
        i += 1
    divisors.sort()
    # print(divisors)

    n = len(divisors)
    from bisect import bisect_left
    for tc in range(int(input())):
        low, high = get_ints()
        l = bisect_left(divisors, low)
        r = bisect_left(divisors, high)
        if l == n:
            print(-1)
            continue

        if r == n or (r < n and divisors[r] != high):
            r -= 1

        if r >= l:
            print(divisors[r])
        else:
            print(-1)


if __name__ == "__main__":
    main()
