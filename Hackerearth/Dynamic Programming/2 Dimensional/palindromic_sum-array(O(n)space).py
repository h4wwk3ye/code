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


'''
 Think of growing a palindromic substring from the center
 by expanding outwards if the characters on both sides match.
 We can determine the length of a palindromic substring
 situated at a given center in O(N) and
 there are only 2*(N-1) possible centers
 (one at each vertex and one between every two consecutive vertices).
 This will give us O(N2) time complexity with no additional space requirement.
 Here’s the implementation:
 '''


def palindromc_substring(s, left, right):
    org_left = left
    while left >= 0 and right < len(s) and s[left] == s[right]:
        left -= 1
        right += 1
    return org_left-left


def main():
    primes = []
    SieveOfEratosthenes(primes, 10000)
    for tc in range(int(input())):
        s = input()
        n = len(s)
        max_length = 1
        for i in range(n):
            s1 = palindromc_substring(s, i-1, i+1)  # when i is the centre
            max_length = max(1+2*s1, max_length)
            s2 = palindromc_substring(s, i, i+1)  # centre bewtween i and i+1
            max_length = max(2*s2, max_length)
        index = bisect.bisect_left(primes, max_length)
        # print(max_length)
        if (max_length == primes[index]):
            print('PRIME')
        else:
            print('NOT PRIME', sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == "__main__":
    main()
