#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <13/Jan/2019 08:57:41 PM>


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
    n, r = get_ints()
    from math import sin, radians
    angle = (360 / n)
    other = radians((180 - angle) / 2)
    angle = radians(angle)
    # print(sin(other))
    ans = r * sin(angle) / ((2 * sin(other)) - sin(angle))
    print(ans)


if __name__ == "__main__":
    main()
