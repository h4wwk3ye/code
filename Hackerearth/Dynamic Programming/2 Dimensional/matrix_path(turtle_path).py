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


def SieveOfEratosthenes(n):

    # Create a boolean array "prime[0..n]" and initialize
    #  all entries it as true. A value in prime[i] will
    # finally be false if i is Not a prime, else true.
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):

        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):

            # Update all multiples of p
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1

    # Print all prime numbers
    for p in range(2, n):
        if prime[p]:
            primes.append(p)


import bisect

'''def solve():
    dp[0][0] = 1
    for i in range(1, n):
        if matrix[i][0] == True:
            dp[i][0] = 1
        else:
            break
    for i in range(1, m):
        if matrix[0][i] == True:
            dp[0][i] = 1
        else:
            break
    for i in range(1, min(n, m)):
        if matrix[i][i] == True:
            dp[i][i] = 3
        else:
            break
    for i in range(1, n):
        for j in range(1, m):
            if matrix[i][j] == True:
                dp[i][j] = (dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]) % mod'''


def solve():
    op = []
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == True:
                if i == 0 and j == 0:
                    dp[i][j] = 1
                elif i == 0:
                    dp[0][j] = dp[0][j-1]
                elif j == 0:
                    dp[i][0] = dp[i-1][0]
                else:
                    dp[i][j] = (dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]) % mod
    ans = dp[n-1][m-1]
    print(ans)


if __name__ == "__main__":
    primes = []
    SieveOfEratosthenes(pow(10, 5)+1)
    n, m = get_ints()
    matrix = [[None for _ in range(m)]for _ in range(n)]
    dp = [[0 for _ in range(m)] for _ in range(n)]
    path = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        inp = get_array()
        for j in range(m):
            index = bisect.bisect_left(primes, inp[j])
            matrix[i][j] = (inp[j] == primes[index])
    solve()
