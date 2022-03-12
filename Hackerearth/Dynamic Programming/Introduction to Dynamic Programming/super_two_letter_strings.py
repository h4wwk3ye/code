#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/super-two-letter-strings/
#

# ///==========Libraries, Constants and Functions=============///


import sys
from math import factorial
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        n, p = get_ints()
        dp = [[0] * (p + 1) for _ in range(n + 2)]
        # dp[i][j] no of string with j consecutive 'X' of length i
        dp[1][0] = 1
        for i in range(1, n + 1):
            for j in range(p):
                dp[i + 1][0] = (dp[i + 1][0] + dp[i][j]) % mod
                if j + 1 < p:
                    dp[i + 1][j + 1] = dp[i][j] % mod
        ans = 0
        for i in range(p):
            ans = (ans + dp[n][i]) % mod
        print(ans)


if __name__ == "__main__":
    main()
