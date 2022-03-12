#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/998/B
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


def recurse(difference, arr, i, b, dp):
    if b < 0:
        return -1*inf
    if i == len(difference)-1:
        return 0
    if dp[i][b] != None:
        return dp[i][b]
    if difference[i] == 0:
        dp[i][b] = max(1+recurse(difference, arr, i+1, b-abs(arr[i+1]-arr[i]), dp),
                       recurse(difference, arr, i+1, b, dp))
    else:
        dp[i][b] = recurse(difference, arr, i+1, b, dp)
    return dp[i][b]


def main():
    n, b = get_ints()
    arr = get_array()
    difference = [0]*n
    count_even, count_odd = 0, 0
    for i in range(n):
        if arr[i] & 1 != 0:
            count_odd += 1
        else:
            count_even += 1
        difference[i] = abs(count_odd-count_even)
    dp = [[None for _ in range(b+1)] for _ in range(n+1)]
    print(recurse(difference, arr, 0, b, dp))


if __name__ == "__main__":
    main()
