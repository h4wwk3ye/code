# !/bin/env python3
# -*- coding: utf-8 -*-


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology and Management,Gwalior

# Question Link
"""
https://www.hackerrank.com/challenges/prime-xor/problem
"""


import sys
import bisect
from collections import defaultdict

inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def get_ints():
    return map(int, sys.stdin.readline().split())


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def SieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    for p in range(2, n):
        if prime[p] == True:
            primes.append(p)


def solve(arr, n):
    count = 0
    for i in range(n):
        dp[i][i] = arr[i]
        index = bisect.bisect_left(primes, arr[i])
        if primes[index] == arr[i]:
            if '1' not in d:
                count += 1
                d['1'].append(arr[i])
            elif arr[i] not in d['1']:
                count += 1
                d['1'].append(arr[i])

    # for i in range(n+1):
        # print(dp[i])
    for i in range(n):
        for j in range(i+1, n):
            dp[i][j] = dp[i][j-1] ^ arr[j]
            index = bisect.bisect_left(primes, dp[i][j])
            if primes[index] == dp[i][j]:
                if 'j-i+1' not in d:
                    count += 1
                    d['j-i+1'].append(dp[i][j])
                elif dp[i][j] not in d['j-i+1']:
                    count += 1
                    d['j-i+1'].append(dp[i][j])
    return count
    # for i in range(n+1):
    # print(dp[i])


if __name__ == "__main__":
    primes = []
    SieveOfEratosthenes(10**6)
    q = int(input())
    for i in range(q):
        d = defaultdict(list)
        n = int(input())
        arr = get_array()
        dp = [[None for _ in range(n+1)] for _ in range(n+1)]
        print(solve(arr, n) % mod)
