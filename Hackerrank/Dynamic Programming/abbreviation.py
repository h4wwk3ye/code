# !/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerrank.com/challenges/abbr/problem
"""


import sys
sys.setrecursionlimit(2000)
inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def get_ints():
    return map(int, sys.stdin.readline().split())


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def solve(A, B, dp):
    n = len(A)
    m = len(B)
    if n == 0 and m == 0:
        return 1
    if n < m:
        return 0
    if B == '':
        if A.lower() == A:
            return 1
        return 0
    if dp[n][m] is not None:
        return dp[n][m]
    if A[-1] == B[-1]:
        dp[n][m] = solve(A[:-1], B[:-1], dp)
        # return solve(A[:-1],B[:-1],dp)
    else:
        if A[-1] == A[-1].upper():  # not equal to B but capital
            return 0
        if A[-1].upper() == B[-1]:
            dp[n][m] = solve(A[:-1]+A[-1].upper(), B, dp) or solve(A[:-1], B, dp)
            # return solve(A[:-1]+A[-1].upper(),B,dp) or solve(A[:-1], B, dp)
        else:
            dp[n][m] = solve(A[:-1], B, dp)
            # return solve(A[:-1], B, dp)
    return dp[n][m]


def main():
    q = int(input())
    for i in range(q):
        str_a = input().rstrip()
        str_b = input().rstrip()
        n = len(str_a)
        m = len(str_b)
        dp = [[None for _ in range(m+1)]for _ in range(n+1)]
        print('YES') if (solve(str_a, str_b, dp)) == 1 else print('NO')


if __name__ == "__main__":
    main()
