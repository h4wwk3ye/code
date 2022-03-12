#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Dec/2018 03:07:49 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/859/C
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(20000)

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    dp = [[0] * 2 for _ in range(n + 1)]
    dp[n][1] = arr[-1]
    dp[n][0] = 0
    for i in range(n - 1, 0, -1):
        dp[i][1] = max(dp[i + 1][0] + arr[i - 1], dp[i + 1][1])
        dp[i][0] = min(dp[i + 1][0] + arr[i - 1], dp[i + 1][1])
    print(sum(arr) - dp[1][1], dp[1][1])


if __name__ == "__main__":
    main()
