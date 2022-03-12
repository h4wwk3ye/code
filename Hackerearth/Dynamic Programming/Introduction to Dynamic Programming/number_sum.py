# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/abcd-26-81bc0a09/

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
    ans = 0
    for i in range(n):
        mex = 1
        f = [0]*N
        for j in range(i, n):
            if arr[j] < N:
                f[arr[j]] = 1
            while f[mex]:
                mex += 1
            ans += mex
    print(ans, sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == "__main__":
    N = 5005
    main()
