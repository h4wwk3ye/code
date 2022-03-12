# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

'''
https://www.hackerearth.com/practice/algorithms/
dynamic-programming/2-dimensional/practice-problems/algorithm/
little-jhool-and-too-many-products-2804a098/
'''
import sys

inf = float("inf")
mod = pow(10, 9)+9


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()


def get_ints():
    return map(int, sys.stdin.readline().split())

# ///==========MAIN=============///


def precompute():
    dp[0][1000] = 1
    for k in range(999, 0, -1):
        for i in range(0, 1000):
            dp[i][k] = dp[i][k+1]
            if i >= k:
                dp[i][k] = (dp[i][k] + dp[i-k][k]) % mod


def main():
    for tc in range(int(input())):
        a, s = get_ints()
        print(dp[a][s])


if __name__ == "__main__":
    dp = [[0 for _ in range(1001)]for _ in range(1001)]
    precompute()
    main()
