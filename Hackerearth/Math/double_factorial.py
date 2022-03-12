#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <16/Feb/2019 08:30:30 PM>


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


N = 10**3
fact = [1] * N


def precompute():
    global N, fact
    fact[1] = 1
    for i in range(2, N):
        fact[i] = (i * fact[i - 1])


def main():
    precompute()
    global fact
    for tc in range(int(input())):
        n, m = get_ints()
        if (n <= 5):
            x = fact[fact[n]]
            print(x % pow(10, m))
        else:
            print(0)


if __name__ == "__main__":
    main()
