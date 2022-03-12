#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <04/Jan/2019 10:31:43 PM>


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


def recurse(arr, i, angle):
    if i == n:
        return True if (angle % 360 == 0) else False
    return (recurse(arr, i + 1, angle + arr[i]) or recurse(arr, i + 1, angle - arr[i]))


if __name__ == "__main__":
        # fast_io()
    n = int(input())
    arr = [0] * n
    for i in range(n):
        arr[i] = int(input())
    print('YES') if recurse(arr, 0, 0) == True else print('NO')
