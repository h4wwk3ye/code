#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/870/C
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def precompute():
    dp = [-1 for _ in range(16)]
    dp[0] = 0
    composite = [4, 6, 9]
    for i in range(1, 16):
        for j in composite:
            if i >= j and dp[i-j] != -1:
                dp[i] = max(dp[i], 1+dp[i-j])
    return dp


def main():
    dp = precompute()
    for tc in range(int(input())):
        n = int(input())
        if n < 16:
            print(dp[n])
        else:
            t = (n-16)//4+1
            print(t+dp[n-4*t])


if __name__ == "__main__":
    main()
