#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <11/Jan/2019 10:25:07 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    h, w = 0, 0
    for tc in range(int(input())):
        t, x, y = input().split()
        x = int(x)
        y = int(y)
        if x < y:
            x, y = y, x
        if t == '+':
            h = max(h, x)
            w = max(w, y)
        elif t == '?':
            if x >= h and y >= w:
                print('YES')
            else:
                print('NO')


if __name__ == "__main__":
    fast_io()
    main()
