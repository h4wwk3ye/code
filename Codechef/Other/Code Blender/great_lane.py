#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Feb/2019 11:54:46 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def modFact(n, p):
    if n >= p:
        return 0

    result = 1
    for i in range(1, n + 1):
        result = (result * i) % p

    return result


def main():
    for tc in range(int(input())):
        n, m = get_ints()
        x = n - m
        ans = (n % mod) * ((n - 1) % mod) // 2
        ans -= (x % mod) * ((x - 1) % mod) // 2
        ans %= mod
        print((ans + 1 + mod) % mod)


if __name__ == "__main__":
    main()
