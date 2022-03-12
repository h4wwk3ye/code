#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#   https://codeforces.com/problemset/problem/698/A
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


def recurse(arr, i, flag):
    if i == len(arr):
        return 0
    if dp[i][flag] != inf:
        return dp[i][flag]

    if arr[i] == 0:
        dp[i][flag] = min(dp[i][flag], 1+recurse(arr, i+1, 2))
    elif arr[i] == 1:
        if flag != 1:
            dp[i][flag] = min(dp[i][flag], recurse(arr, i+1, 1), 1+recurse(arr, i+1, 2))
        else:
            dp[i][flag] = min(dp[i][flag], 1+recurse(arr, i+1, 2))
    elif arr[i] == 2:
        if flag != 0:
            dp[i][flag] = min(dp[i][flag], recurse(arr, i+1, 0), 1+recurse(arr, i+1, 2))
        else:
            dp[i][flag] = min(dp[i][flag], 1+recurse(arr, i+1, 2))
    elif arr[i] == 3:
        if flag == 0:
            dp[i][flag] = min(dp[i][flag], 1+recurse(arr, i+1, 2), recurse(arr, i+1, 1))
        elif flag == 1:
            dp[i][flag] = min(dp[i][flag], 1+recurse(arr, i+1, 2), recurse(arr, i+1, 0))
        elif flag == 2:
            dp[i][flag] = min(dp[i][flag], 1+recurse(arr, i+1, 2),
                              recurse(arr, i+1, 0), recurse(arr, i+1, 1))
    return dp[i][flag]


def main():
    n = int(input())
    arr = get_array()
    print(recurse(arr, 0, 2))


if __name__ == "__main__":
    dp = [[inf for _ in range(3)] for _ in range(101)]
    main()
