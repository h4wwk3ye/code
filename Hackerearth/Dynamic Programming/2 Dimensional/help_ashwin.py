#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <02/Jan/2019 07:08:51 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/help-ashwin/
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


def recurse(matrix, i, j):
    if i >= n or j >= m:
        return 0
    c = matrix.copy()
    if i + 1 < n:
        c[i + 1][j] = 0
    print(i, j, matrix, c)
    return max(recurse(c, i + 1, 0) + matrix[i][j], recurse(matrix, i, j + 1))


if __name__ == "__main__":
        # fast_io()
    for tc in range(int(input())):
        n, m = get_ints()
        matrix = [0] * n
        for i in range(n):
            matrix[i] = get_array()
        print(recurse(matrix, 0, 0))
