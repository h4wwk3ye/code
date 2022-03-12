#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/534/B
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
    v1, v2 = get_ints()
    t, d = get_ints()
    dp = [0]*(t+1)
    dp[1] = v1
    dp[-1] = v2
    for i in range(2, t):
        dp[i] = min(d+dp[i-1], dp[-1]+d*(t-i))
    print(sum(dp))


if __name__ == "__main__":
    main()
