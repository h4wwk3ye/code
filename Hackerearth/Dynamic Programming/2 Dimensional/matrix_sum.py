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


def main():
    N, M = get_ints()
    matrix = [[None for _ in range(M)] for _ in range(N)]
    for i in range(N):
        inp = get_array()
        for j in range(M):
            matrix[i][j] = inp[j]
    dp = [[0 for _ in range(M)] for _ in range(N)]
    dp[0][0] = matrix[0][0]
    for i in range(1, N):  # filling 1 st column
        dp[i][0] = dp[i-1][0]+matrix[i][0]
    for i in range(1, M):  # filling 1 st row
        dp[0][i] = dp[0][i-1]+matrix[0][i]
    for i in range(1, N):
        for j in range(1, M):
            dp[i][j] = dp[i-1][j]+dp[i][j-1]+matrix[i][j]-dp[i-1][j-1]
    # print(dp)
    for i in range(int(input())):
        x, y = get_ints()
        print(dp[x-1][y-1], sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == "__main__":
    main()
