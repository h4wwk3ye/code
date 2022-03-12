#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/dhoni-and-holidays/
#   Same as- https://codeforces.com/problemset/problem/698/A

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def recurse(i, flag):
    if i == n:
        return 0
    if dp[i][flag] != inf:
        return dp[i][flag]
    if arr[i] == 0:
        dp[i][flag] = 1+recurse(i+1, 2)
    elif arr[i] == 1:
        if flag == 0:
            dp[i][flag] = 1+recurse(i+1, 2)
        else:
            dp[i][flag] = min(recurse(i+1, 0), 1+recurse(i+1, 2))
    elif arr[i] == 2:
        if flag == 1:
            dp[i][flag] = 1+recurse(i+1, 2)
        else:
            dp[i][flag] = min(recurse(i+1, 1), 1+recurse(i+1, 2))
    elif arr[i] == 3:
        if flag == 2:
            dp[i][flag] = min(recurse(i+1, 0), recurse(i+1, 1), 1+recurse(i+1, 2))
        elif flag == 0:
            dp[i][flag] = min(recurse(i+1, 1), 1+recurse(i+1, 2))
        elif flag == 1:
            dp[i][flag] = min(recurse(i+1, 0), 1+recurse(i+1, 2))
    return dp[i][flag]


if __name__ == "__main__":
    n = int(input())
    arr = get_array()
    dp = [[inf]*3 for _ in range(101)]
    # flag-0 for academy #1 for car and #2 for holiday
    print(recurse(0, 2))
