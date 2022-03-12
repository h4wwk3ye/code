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


'''def solve():
    for i in range(1, m+1):
        for j in range(1, n+1):
            if X[i-1] == Y[j-1]:
                dp[i][j] = 1+dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
'''


def solve(i, j):
    if dp[i][j] is not None:
        return dp[i][j]
    if i == 0 or j == 0:
        dp[i][j] = 0
    elif X[i-1] == Y[j-1]:
        dp[i][j] = 1+solve(i-1, j-1)
    else:
        dp[i][j] = max(solve(i-1, j), solve(i, j-1))
    return dp[i][j]


if __name__ == "__main__":
    X = "AGGTAB"
    Y = "GXTXAYB"
    m = len(X)
    n = len(Y)
    dp = [[None for i in range(n+1)] for i in range(m+1)]
    solve(m, n)
    for i in range(m+1):
        print(dp[i], sep=' ', end='\n', file=sys.stdout, flush=False)
