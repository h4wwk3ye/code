#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/1081/C
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 998244353


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n, m, k = get_ints()
    dp = [[0 for _ in range(2005)] for _ in range(2005)]
    # dp[i][j] is the ways of coloring that there are j bricks of
    # different color from its adjacent left brick
    dp[1][0] = m
    for i in range(1, n):
        for j in range(k+1):
            # i+1'th brick has same color as that of i'th brick
            dp[i+1][j] = (dp[i+1][j]+dp[i][j]) % mod
            # m-1 ways of coloring this next block with a different color
            dp[i+1][j+1] = ((dp[i+1][j+1]+dp[i][j])*(m-1)) % mod
    print(dp[n][k])


if __name__ == "__main__":
    main()
