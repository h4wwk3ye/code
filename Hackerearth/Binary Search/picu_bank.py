#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Mar/2019 09:47:58 PM>


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
    for tc in range(int(input())):
        d, a, m, b, x = get_ints()
        x -= d
        p = a*m+b
        ans = (m+1)*(x//p)
        u = (x//p)*p
        x -= u
        from math import ceil
        ans += ceil(x/a)
        print(ans)


if __name__ == "__main__":
    main()
