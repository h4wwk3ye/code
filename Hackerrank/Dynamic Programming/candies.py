# !/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerrank.com/challenges/candies/problem
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
    n = int(input())
    arr = [0]*n
    for i in range(n):
        arr[i] = int(input())
    forward = [1]*n
    backward = [1]*n
    for i in range(1, n):
        if arr[i] > arr[i-1]:
            forward[i] = 1+forward[i-1]
        else:
            forward[i] = 1
    for i in range(n-2, -1, -1):
        if arr[i] > arr[i+1]:
            backward[i] = 1+backward[i+1]
        else:
            backward[i] = 1
    total = 0
    for i in range(n):
        total += max(forward[i], backward[i])
    print(total)


if __name__ == "__main__":
    main()
