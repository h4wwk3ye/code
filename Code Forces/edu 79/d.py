#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 27/Dec/19 09:59:35 PM


import sys


def main():
    n = int(input())
    arr = [0] * n
    for i in range(n):
        arr[i] = get_array()[1:]
    cnt = [0] * (10 ** 6 + 5)
    for i in arr:
        for j in i:
            cnt[j] += 1

    ans = 0
    mod = 998244353
    for i in range(n):
        x = 0
        for j in range(len(arr[i])):
            if cnt[arr[i][j]] != n:
                num = 1
                den = 1
                den *= len(arr[i])
                den %= mod
                den *= n
                den %= mod
                num *= n - cnt[arr[i][j]]
                num %= mod
                x += num * pow(den, mod - 2, mod)
                x %= mod
        if x != 0:
            ans += x * pow(2, mod - 2, mod)
            ans %= mod

    print((1 - ans + mod) % mod)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
