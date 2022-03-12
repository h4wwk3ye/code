#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <03/Jun/2019 08:31:35 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n = int(input())

    def primes_sieve(limit):
        a = [True] * limit                       # Initialize the primality list
        a[0] = a[1] = False

        for (i, isprime) in enumerate(a):
            if isprime:
                yield i
                for n in range(i * i, limit, i):     # Mark factors non-prime
                    a[n] = False
    primes = list(primes_sieve(n + 1))
    # print(primes)
    arr = [0] * (n + 1)
    curr = 1
    for i in range(2, n + 1):
        if (arr[i] != 0):
            continue
        j = i
        while j <= n:
            arr[j] = curr
            j += i
        curr += 1
    print(*arr[2:])


if __name__ == "__main__":
    main()
