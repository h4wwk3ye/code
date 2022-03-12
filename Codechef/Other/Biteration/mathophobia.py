#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <17/Mar/2019 09:50:12 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def primes_sieve(limit):
    a = [True] * limit                       # Initialize the primality list
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in range(i * i, limit, i):     # Mark factors non-prime
                a[n] = False


def precompute():
    global prime
    prime = list(primes_sieve(10**5))


def main():
    precompute()
    new = set()
    print(len(prime))
    for i in range(len(prime)):
        for j in range(len(prime)):
            x = prime[i]*prime[j]
            if (x > 10**11):
                print("YES")
                sys.exit()
                break
            new.add(x)
    p = list(new)
    p.sort()
    print(p)
    from bisect import bisect_left
    # print(new)
    for tc in range(int(input())):
        n = int(input())
        index = bisect_left(p, n)
        if index == 0:
            print(p[0] if p[0] == n else -1)
        else:
            print(p[index-1])


if __name__ == "__main__":
    main()
