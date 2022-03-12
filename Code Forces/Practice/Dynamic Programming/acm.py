#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/414/B
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
    n, k = get_ints()
    dp = [[0]*(n+1) for _ in range(k+1)]
    # dp[i][j] no of sequences of length i that end with j
    for i in range(1, n+1):
        dp[1][i] = 1
    for i in range(1, k):
        for j in range(1, n+1):
            for l in range(j, n+1, j):  # factors of j
                dp[i+1][l] = (dp[i+1][l]+dp[i][j]) % mod

    ans = 0
    for i in range(1, n+1):
        ans = (ans+dp[k][i]) % mod
    print(ans)


if __name__ == "__main__":
    main()
