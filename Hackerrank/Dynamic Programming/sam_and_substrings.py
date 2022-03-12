# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
# https://www.hackerrank.com/challenges/sam-and-substrings/problem


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


def solve(str):
    n = len(str)
    op = int(str[0])
    tmp = int(str[0])
    for i in range(1, n):
        tmp = tmp*10+(i+1)*int(str[i])
        tmp %= mod
        op += tmp
        op %= mod
    return op


if __name__ == "__main__":
    str = input().strip()
    print(solve(str))
