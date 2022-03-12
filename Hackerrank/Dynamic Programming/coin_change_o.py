# !/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerrank.com/challenges/coin-change/problem
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


def solve():
    dp = [0 for i in range(n+1)]
    for i in range(m):
        if coins[i] > n:
            continue
            # there is always 1 way of reaching this
            # n by using coin of that value
        dp[coins[i]] += 1
        for j in range(coins[i]+1, n+1):
            dp[j] += dp[j-coins[i]]
        # all values that can be reached by using this coin
    # print(dp)
    return dp[n]


if __name__ == "__main__":
    n, m = get_ints()
    coins = get_array()
    print(solve())
