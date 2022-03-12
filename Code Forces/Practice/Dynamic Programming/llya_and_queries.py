#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/313/B
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
    s = input()
    dp = [0]*(len(s)+1)
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            dp[i] = 1+dp[i-1]
        else:
            dp[i] = dp[i-1]
    for tc in range(int(input())):
        l, r = get_ints()
        l -= 1
        r -= 1
        print(dp[r]-dp[l])


if __name__ == "__main__":
    main()
