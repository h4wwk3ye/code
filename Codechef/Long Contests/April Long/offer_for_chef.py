#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <12/Apr/2019 11:50:09 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///

import sys
sys.setrecursionlimit(10**6)
#import resource
#resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


def solve(dp, k, start, curr):
    l = len(dp[0])
    if k == 1:
        return curr & dp[l-start-1][start]
    mx = 0
    for i in range(1, l-start-k+1):
        x = curr & dp[i-1][start]
        if x == 0:
            continue
        mx = max(mx, solve(dp, k-1, start + i, x))
    return mx


def main():
    n = int(input())
    arr = get_array()
    for tc in range(int(input())):
        k = int(input())
        t = get_array()
        for i in range(n):
            t[i] = t[i]*arr[i]
        final = []
        for i in t:
            if i != 0:
                final.append(i)
        if (k > len(final)):
            print(0)
            continue
        else:
            l = len(final)
            dp = [[] for _ in range(n-k+1)]
            dp[0] = final
            for i in range(1, n-k+1):
                dp[i] = [0]*(l-i)
                for j in range(0, len(dp[i])):
                    dp[i][j] = dp[i-1][j+1]+dp[0][j]
            print(solve(dp, k, 0, (2**32)//2-1))


if __name__ == "__main__":
    main()
