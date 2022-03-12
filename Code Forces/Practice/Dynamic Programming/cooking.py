#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/1040/B
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def recurse(i, j):
    if i > n:
        if j >= n+1:
            return 0
        return inf
    ans = inf
    if dp[i][j] != -1:
        return dp[i][j]
    if i-j < k:
        d = min(ans, recurse(i+1, j))
        if d < ans:
            opti[i][j] = 0
            ans = d
    if j == 1 or i-j == k:
        d = min(ans, recurse(i+k+1, i+k+1)+1)
        if d < ans:
            opti[i][j] = 1
            ans = d
    dp[i][j] = ans
    return ans


if __name__ == "__main__":
    n, k = get_ints()
    dp = [[-1]*1005 for _ in range(1005)]
    opti = [[0]*1005 for _ in range(1005)]
    print(recurse(1, 1))
    i, j = 1, 1
    while i <= n:
        if opti[i][j] == 0:
            i += 1
        else:
            print(i, end=' ')
            j = i+k+1
            i = i+k+1
