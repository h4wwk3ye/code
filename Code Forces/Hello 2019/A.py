#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <04/Jan/2019 08:18:45 PM>


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
    s = input()
    arr = list(input().split())
    for i in arr:
        if i[0] == s[0] or i[1] == s[1]:
            print('YES')
            return
    print('NO')


if __name__ == "__main__":
        # fast_io()
    main()
