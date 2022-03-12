# !/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerrank.com/challenges/sherlock-and-cost/problem
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


if __name__ == "__main__":

    # dp[i][0] stores maximum value of first i elements if A[i]==1
    # dp[i][1] stores maximum value of first i elements if A[i]==B[i]
    for tc in range(int(input())):
        dp = [[0 for _ in range(2)] for _ in range(n+1)]
        n = int(input())
        arr = get_array()
        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+abs(arr[i-1]-1))
        # dp[i][0] contains max of 2 values bewteen dp[i-1][0]+(1-1) and
        # dp[i-1][1]+abs(arr[i]-1)
        # [because dp[i][0] contains max value if A[i]==1 so either 1-1+dp[i-1][0]
        # or dp[i-1][1]+abs(arr[i-1]-1)]
            dp[i][1] = max(dp[i-1][0]+abs(arr[i]-1), dp[i-1][1]+abs(arr[i-1]-arr[i]))
        # similarly for dp[i-1][1]
        print(max(dp[n-1][0], dp[n-1][1]))
