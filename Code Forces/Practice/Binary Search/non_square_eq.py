#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <11/Mar/2019 11:03:19 AM>


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


def sum_digits(n):
    r = 0
    while n:
        r, n = r + n % 10, n // 10
    return r


def main():
    n = int(input())
    from math import sqrt
    l = int(sqrt(n))
    # print(l)
    for i in range(l+50, l-101, -1):
        if i >= 1:
            if (i**2+sum_digits(i)*i) == n:
                print(i)
                return
        else:
            break
    print(-1)


if __name__ == "__main__":
    main()
