# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

inf = float("inf")
mod = 1000000007


import sys


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def solve(n, arr):
    dp = [0]*(n+1)
    dp[0] = 1
    for j in arr:
        for i in range(j, n+1):
            dp[i] = (dp[i]+dp[i-j]) % mod
            #print(i, dp)
    return dp[n]


def main():
    m, n = map(int, input().split())
    arr = get_array()
    print(solve(n, arr))


if __name__ == "__main__":
    main()
