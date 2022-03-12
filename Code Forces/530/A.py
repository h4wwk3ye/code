#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <05/Jan/2019 10:10:30 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
#from atexit import register
#from io import StringIO as stream

inf = float("inf")
mod = 1000000007


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    w, h = get_ints()
    u1, d1 = get_ints()
    u2, d2 = get_ints()
    for i in range(h, -1, -1):
        w += i
        if d1 == i:
            w -= u1
        if w < 0:
            w = 0
        if d2 == i:
            w -= u2
        if w < 0:
            w = 0

    print(w)


if __name__ == "__main__":
        # fast_io()
    main()
