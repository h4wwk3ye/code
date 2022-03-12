#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/910/A
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(2000)
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def recurse():
    for i in range(2, n+1):
        if arr[i-1] == '1':
            for j in range(d+1):
                if i-j >= 1:
                    dp[i] = min(dp[i], 1+dp[i-j])
    return dp[n] if dp[n] != inf else -1


if __name__ == "__main__":
    n, d = get_ints()
    arr = input()
    dp = [inf]*(n+1)
    dp[1] = 0
    print(recurse())
