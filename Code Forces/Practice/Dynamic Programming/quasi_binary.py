#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/538/B
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def precompute(x):
    while x > 0:
        d = x % 10
        if d != 0 and d != 1:
            return False
        x //= 10
    return True


def main():
    coins = []
    for i in range(int(pow(10, 6))+1):
        if precompute(i) == True:
            coins.append(i)
    # print(coins)
    # print(len(coins))
    n = int(input())
    dp = [inf for _ in range(n+1)]
    opti = [0 for _ in range(n+1)]
    dp[0] = 0
    for i in range(1, n+1):
        for j in coins:
            if j > i:
                break
            if 1+dp[i-j] < dp[i]:
                dp[i] = 1+dp[i-j]
                opti[i] = j
    print(dp[n])
    op = []
    i = n
    while i != 0:
        op.append(opti[i])
        i -= opti[i]
    print(*op)


if __name__ == "__main__":
    main()
