#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/798/B
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
    n = int(input())
    s = [0]*n
    for i in range(n):
        s[i] = list(input().strip())
        s[i] += s[i]
        # doubling as we will get the rotated string
        # just by slicing   ex-abcdabcd
    s.insert(0, '')
    k = len(s[1])//2
    dp = [[inf for _ in range(k)] for _ in range(n+1)]
    for i in range(k):
        dp[1][i] = i
    for i in range(2, n+1):
        for j in range(k):
            for x in range(k):
                if s[i][j:j+k] == s[i-1][x:x+k]:
                    dp[i][j] = min(dp[i][j], j+dp[i-1][x])

    ans = min(dp[n])
    print(ans) if ans != inf else print(-1)


if __name__ == "__main__":
    main()
