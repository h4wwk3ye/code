# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior


import sys
inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()


def get_ints():
    return map(int, sys.stdin.readline().split())

# ///==========MAIN=============///


if __name__ == "__main__":
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        total = sum(arr)
        if total % 2 != 0:
            print('NO')
        else:
            mx = max(arr)
            #arr.insert(0, 0)
            dp = [[0 for i in range(total//2+1)]for i in range(n+1)]

            for i in range(1, n+1):
                for j in range(1, total//2+1):
                    if arr[i-1] <= j:
                        dp[i][j] = max(arr[i-1]+dp[i-1][j-arr[i-1]], dp[i-1][j])
                    else:
                        dp[i][j] = dp[i-1][j]

            if dp[n][total//2] == total//2:
                print('YES')
            else:
                print('NO')
