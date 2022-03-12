#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/contest/1096/problem/B
#

# ///==========Libraries, Constants and Functions=============///


import sys
from math import factorial
inf = float("inf")
mod = 998244353


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    s = input().strip()
    x = 0
    for i in range(n-1):
        if s[i] == s[i+1]:
            x += 1
        else:
            break
    y = 0
    for i in range(n-1, 0, -1):
        if s[i] == s[i-1]:
            y += 1
        else:
            break
    count = 3
    count = (count+x) % mod
    count = (count+y) % mod
    if s[0] == s[-1]:
        count += 1
        count = (count+x) % mod
        count = (count+y) % mod
        count = (count+(x*y)) % mod
    print(count)


if __name__ == "__main__":
    main()
