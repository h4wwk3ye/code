#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/628/B
#

# ///==========Libraries, Constants and Functions=============///


import sys
from itertools import permutations, combinations

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    s = input().strip()
    n = len(s)
    count = 0
    for i in s:
        if int(i) % 4 == 0:
            count += 1
    for i in range(1, n):
        if int(s[i-1]+s[i]) % 4 == 0:
            count += i
    print(count)


if __name__ == "__main__":
    main()
