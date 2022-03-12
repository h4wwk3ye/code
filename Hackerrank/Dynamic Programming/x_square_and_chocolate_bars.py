#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-chocolates-bars-2/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def solve(s, i):
    if i >= len(s):
        return 0


def main():
    for tc in range(int(input())):
        s = input().strip()
        n = len(s)
        dp = [0 for _ in range(n)]
        dp[2] = 1 if (s[2] != s[1] or s[1] != s[0]) else 0
        mx = 0
        for i in range(2, n):
            if s[i] != s[i-1] or s[i-1] != s[i-2]:
                dp[i] = 1+dp[i-3]
                mx = max(dp[i], mx)
        print(n-3*mx)


if __name__ == "__main__":
    main()
