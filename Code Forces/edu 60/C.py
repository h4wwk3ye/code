#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <18/Feb/2019 10:38:00 PM>


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
    x1, y1 = get_ints()
    x2, y2 = get_ints()
    n = int(input())
    s = input().strip()
    if x2 > x1:
        h = 1
    else:
        if x2 < x1:
            h = -1
        else:
            h = 0
    if y2 > y1:
        v = 1
    else:
        if y2 < y1:
            v = -1
        else:
            v = 0
    if x1 == x2 and y1 == y2:
        print(0)
        return
    vertical = y2 - y1
    horizontal = x2 - x1
    u, d, l, r = 0, 0, 0, 0
    for i in s:
        if i == 'U':
            u += 1
        elif i == 'D':
            d += 1
        elif i == 'L':
            l += 1
        elif i == 'R':
            r += 1
    if


if __name__ == "__main__":
    main()
