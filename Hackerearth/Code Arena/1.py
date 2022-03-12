# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior


import sys

inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()


def get_ints():
    return map(int, sys.stdin.readline().split())


# ///==========MAIN=============///
from math import factorial


def main():
    n, k = get_ints()
    arr = get_array()
    mul = 1
    for i in arr:
        mul *= i
    arr.sort()
    x = 1
    for i in range(mul//2):
        if i % mul == 0:


if __name__ == "__main__":
    main()
