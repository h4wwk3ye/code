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


def solve():
    dp[1][1] = 1
    mx = 1
    for i in range(2, n+1):
        if matrix[i][1] > matrix[i-1][1]:
            dp[i][1] = 1+dp[i-1][1]
            mx = max(dp[i][1], mx)
        else:
            break
    for j in range(2, m+1):
        if matrix[1][j] > matrix[1][j-1]:
            dp[1][j] = 1+dp[1][j-1]
            mx = max(dp[1][j], mx)
        else:
            break
    '''for i in range(n+1):
        print(dp[i])
    print("\n")'''
    for i in range(2, n+1):
        for j in range(2, m+1):
            if matrix[i][j] > matrix[i-1][j] and dp[i-1][j] != 0:
                dp[i][j] = 1+dp[i-1][j]
            if matrix[i][j] > matrix[i][j-1] and dp[i][j-1] != 0:
                dp[i][j] = 1+dp[i][j-1]
            mx = max(dp[i][j], mx)

    '''for i in range(n+1):
        print(dp[i])'''
    return mx


if __name__ == "__main__":
    for tc in range(int(input())):
        n, m = get_ints()
        matrix = [[0 for _ in range(m+1)] for _ in range(n+1)]
        dp = [[0 for i in range(m+1)] for i in range(n+1)]
        for i in range(n):
            inp = get_array()
            for j in range(m):
                matrix[i+1][j+1] = inp[j]
        print(solve())
