#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/987/C
#

# ///==========Libraries, Constants and Functions=============///


import sys
import operator
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    size = get_array()
    cost = get_array()
    dp = [inf for _ in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            if size[j] > size[i]:
                dp[i] = min(dp[i], cost[j])
    print(dp)
    ans = inf
    for i in range(n):
        for j in range(i+1, n):
            if size[j] > size[i]:
                ans = min(ans, dp[j]+cost[i]+cost[j])
    print(ans) if ans != inf else print(-1)


if __name__ == "__main__":
    main()
