#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <07/Jun/2019 12:41:30 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    N = int(1e5 + 5)
    dp = [1] * N
    for i in range(N - 3):
        dp[i + 2] += dp[i]
    for i in range(N - 4):
        dp[i + 4] += dp[i]

    # print(*dp[:10])
    for tc in range(int(input())):
        p, d = get_ints()
        print(dp[p - d])


if __name__ == "__main__":
    main()
