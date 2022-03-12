#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Dec/2018 10:17:15 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/choosing-the-judges-7/
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(15000)
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def recurse(arr, i, dp):
    if i >= len(arr):
        return 0
    if dp[i] != -1:
        return dp[i]

    dp[i] = max(recurse(arr, i + 1, dp), recurse(arr, i + 2, dp) + arr[i])
    return dp[i]


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        dp = [-1 for _ in range(n + 1)]
        print('Case ', tc + 1, ': ', recurse(arr, 0, dp), sep='')


if __name__ == "__main__":
    main()
