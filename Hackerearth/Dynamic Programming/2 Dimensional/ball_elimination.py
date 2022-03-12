# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

'''https://www.hackerearth.com/practice/algorithms/dynamic-programming/
2-dimensional/practice-problems/algorithm/ball-elimination/
'''
# https://discuss.codechef.com/questions/92881/ball-elimination-dp-problem
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


def solve(i, j):
    if dp[i][j] is not None:
        return dp[i][j]
    if i > j:
        res = 0
    elif i == j:
        res = 1
    else:
        res = inf
        if s[i] == s[j]:
            res = solve(i+1, j-1)
        else:
            for k in range(i, j):
                res = min(res, solve(i, k)+solve(k+1, j))
    dp[i][j] = res
    return res


if __name__ == "__main__":
    n = int(input())
    s = get_array()
    dp = [[None for i in range(n)] for i in range(n)]
    print(solve(0, n-1))
