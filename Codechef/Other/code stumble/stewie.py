#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <15/Jan/2019 10:27:42 PM>


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


def main():
    h, w, x, y = get_ints()
    from math import gcd
    p = gcd(x, y)
    x = x // p
    y = y // p

    if x > h or y > w:
        print(0, 0)
        return

    l = h // x
    m = w // y
    if l < m:
        print(l * x, l * y)
    else:
        print(m * x, m * y)


if __name__ == "__main__":
    main()
