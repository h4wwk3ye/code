# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://codeforces.com/problemset/problem/580/A
"""


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


def main():
    n = int(input())
    arr = get_array()
    curr_max = 1
    mx = 1
    for i in range(1, n):
        if arr[i] >= arr[i-1]:
            curr_max += 1
            mx = max(curr_max, mx)
        else:
            curr_max = 1
    print(mx)


if __name__ == "__main__":
    main()
