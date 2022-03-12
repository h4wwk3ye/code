#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <09/Apr/2019 01:34:29 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///

import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


# ///==========MAIN=============///

from itertools import permutations
from bisect import bisect_left

prime = [True]*(10**6+5)


def SieveOfEratosthenes(n):

    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1


def main():
    SieveOfEratosthenes(10**6)
    for tc in range(int(input())):
        n = int(input())
        flag = 0
        while True:
            x = n
            a = permutations(x)

            for i in a:
                curr = int(''.join(i))
                if prime[curr] == True:
                    flag = 1
                    print(n)
                    break
            if flag == 1:
                break
            n -= 1


if __name__ == "__main__":
    main()
