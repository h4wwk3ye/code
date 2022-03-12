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


def palindrome(s):
    n = len(s)
    dp = [[True for _ in range(n+1)] for _ in range(n+1)]
    count = 0
    for j in range(1, n):
        for i in range(1, n-j+1):
            dp[i][i+j] = dp[i+1][i+j-1] and (s[i] == s[i+j-1])
            if dp[i][i+j]:
                count += 1
    return count


if __name__ == "__main__":
    s = input()
    print(palindrome(s))
