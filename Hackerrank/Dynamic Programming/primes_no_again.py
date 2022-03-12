#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/prime-numbers-again/
#

# ///==========Libraries, Constants and Functions=============///


import sys
import bisect
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

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


def precompute():
    for i in range(1, 10005):
        for j in primes:
            if i >= j:
                dp[i] = min(dp[i], 1+dp[i-j])
            else:
                break


def main():
    for tc in range(int(input())):
        print(dp[int(input())])


if __name__ == "__main__":
    primes = []
    SieveOfEratosthenes(10005)
    extra = []
    for i in primes:
        if i**i < 10005:
            extra.append(i**i)
    for i in extra:
        bisect.insort_left(primes, i)
    # print(primes)
    dp = [inf]*(10005)
    dp[0] = 0
    precompute()
    main()
