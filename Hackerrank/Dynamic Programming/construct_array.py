# !/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerrank.com/challenges/construct-the-array/problem
"""


import sys

inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def get_ints():
    return map(int, sys.stdin.readline().split())


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def solve():
    # dp[i][j] is the number of ways to make an array of length i ending with j
    dp = [[0 for _ in range(3)] for _ in range(n+1)]
    # 3 because dp[i][2]==d[i][3]==dp[i][4]==....==dp[i][n-1]

    dp[1][1] = 1
    dp[1][2] = 0
    for i in range()


if __name__ == "__main__":
    n, k, x = get_ints()
    solve()
