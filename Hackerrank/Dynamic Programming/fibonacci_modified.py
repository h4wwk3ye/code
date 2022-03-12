# !/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerrank.com/challenges/fibonacci-modified/problem
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


def main():
    t1, t2, n = get_ints()
    dp = [0 for _ in range(n+1)]
    dp[1] = t1
    dp[2] = t2
    for i in range(3, n+1):
        dp[i] = dp[i-2]+pow(dp[i-1], 2)
    print(dp[n])


if __name__ == "__main__":
    main()
