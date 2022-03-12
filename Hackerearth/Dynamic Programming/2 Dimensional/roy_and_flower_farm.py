# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerearth.com/practice/algorithms/
dynamic-programming/2-dimensional/practice-problems/algorithm/
roy-and-flower-farm/
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


def solve(n, p):
    for i in range(1, n+1):
        for j in range(1, p+1):
            if fertilising_cost[i-1] <= j:
                dp[i][j] = max(dp[i-1][j-fertilising_cost[i-1]]+selling_cost[i-1], dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    max_profit = dp[n][p]
    i = n
    j = p
    while j >= 0 and max_profit == dp[i][j]:
        j -= 1
    j += 1
    return j, max_profit+p


if __name__ == "__main__":
    for tc in range(int(input())):
        n, p = get_ints()
        dp = [[0 for _ in range(p+1)] for _ in range(n+1)]
        selling_cost = [None]*n
        fertilising_cost = [None]*n
        for i in range(n):
            x, y = get_ints()
            selling_cost[i] = x-y
            fertilising_cost[i] = y
        print(*solve(n, p))
