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


def solve(n, W):
    for i in range(1, n+1):
        for j in range(W+1):
            if j >= weight[i-1]:
                dp[i][j] = max(dp[i-1][j], value[i-1]+dp[i-1][j-weight[i-1]])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][W]


if __name__ == "__main__":
    for tc in range(int(input())):
        n = int(input())
        W = int(input())
        weight = get_array()
        value = get_array()
        dp = [[0 for _ in range(W+1)] for _ in range(n+1)]
        print(solve(n, W))
