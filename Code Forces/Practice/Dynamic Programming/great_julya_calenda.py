#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/331/C1
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def recurse(n):
    dp = [inf for _ in range(1000005)]
    for i in range(10):
        dp[i] = 1
    for i in range(10, 1000001):
        x = i
        while x > 0:
            r = x % 10
            x //= 10
            if r > 0:
                dp[i] = min(dp[i], dp[i-r]+1)
    return dp[n]


def main():
    n = int(input())
    if n == 0:
        print(0)
        return
    print(recurse(n))


if __name__ == "__main__":
    main()
