#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Dec/2018 12:07:42 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
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


def recurse(i, dp):
    if i < 0:
        return inf
    if i == 0:
        return 0
    if dp[i] != inf:
        return dp[i]
    dp[i] = min(1 + recurse(i - 10, dp), 1 + recurse(i - 12, dp))
    return dp[i]


def main():
    for tc in range(int(input())):
        dp = [inf for _ in range(115)]
        n = int(input())
        ans = recurse(n, dp)
        print(ans) if ans != inf else print(-1)


if __name__ == "__main__":
    main()
