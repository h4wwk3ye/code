#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <25/Feb/2019 09:58:23 PM>


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
    from math import gcd
    for tc in range(int(input())):
        n, a, b = get_ints()
        a = (pow(n, a, mod)-1)
        b = (pow(n, b, mod)-1)
        # print()
        print((gcd(a, b)+1) % mod)


if __name__ == "__main__":
    main()
