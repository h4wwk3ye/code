#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Dec/2018 11:56:34 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hp-and-counting-number-of-ways-1d73a6a4/
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


def main():
    for tc in range(int(input())):
        x, k = get_ints()
        dp = [0] * (x + 1)
        dp[0] = 1
        ans = 0
        for i in range(1, x + 1):
            if i > k:
                ans -= dp[i - k - 1]
            ans = (ans + dp[i - 1]) % mod
            dp[i] = ans
        print(ans)


if __name__ == "__main__":
    main()
