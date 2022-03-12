# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior


import sys
import bisect

inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()


def get_ints():
    return map(int, sys.stdin.readline().split())

# ///==========MAIN=============///


def SieveOfEratosthenes(primes, n):

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


def main():
    primes = []
    SieveOfEratosthenes(primes, 10000)
    for tc in range(int(input())):
        s = input()
        n = len(s)

        '''If S[3..4] is not a palindrome,
        then S[2..5] and S[1..6] are not going to be palindromes
        and there’s no point in checking.
        Similarly, if S[3..4] is a palindrome,
        then for S[2..5] to be a palindrome,
        we need only check S[2] == S[5].
        We can get rid of this repeated computation
        with the following dynamic programming formulation:
        P(i, j) = true if i >= j else P(i+1, j-1) && S[i] == S[j]
        We can keep track of the largest palindromic length
        and its starting position,
        leading to the following simple implementation:'''
        dp = [[True for _ in range(n+1)] for _ in range(n+1)]
        max_length = 1  # each character is iteself a palindrome
        for j in range(1, n):
            for i in range(1, n-j+1):
                # i-1 and i+j-1 in s because its 0 index based
                dp[i][i+j] = dp[i+1][i+j-1] and (s[i-1] == s[i+j-1])
                if dp[i][i+j] and j+1 > max_length:
                    max_length = j+1
        index = bisect.bisect_left(primes, max_length)
        if (max_length == primes[index]):
            print('PRIME')
        else:
            print('NOT PRIME', sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == "__main__":
    main()
