# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

'''https://www.hackerearth.com/practice/
algorithms/dynamic-programming/2-dimensional/practice-problems/
algorithm/number-formation-1cae96c5/'''
import sys
from math import factorial
inf = float("inf")
mod = 720720


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()


def get_ints():
    return map(int, sys.stdin.readline().split())

# ///==========MAIN=============///


def solve(arr, n, k):
    dp = [[0 for _ in range(k+1)] for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(1, n+1):
        dp[i][0] = 1
    # print(dp)
    for i in range(1, n+1):
        for j in range(1, k+1):
            if j == 1 and arr[i-1] == 0:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = (dp[i][j]+dp[i-1][j]+dp[i-1][j-1]) % mod
    if k == 1:
        return n
    else:
        return dp[n][k]


if __name__ == "__main__":
    n = int(input())
    arr = get_array()
    k = int(input())
    print(solve(arr, n, k))
