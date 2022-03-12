#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/166/E
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())

    D = 1
    ABC = 0
    for i in range(1, n+1):
        nD = (ABC*3+D-D) % mod
        nABC = (ABC*3+D-ABC) % mod
        D, ABC = nD, nABC
    print(D)


main()
