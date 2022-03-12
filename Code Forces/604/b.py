#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 06/Dec/19 09:35:56 AM


import sys


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        d = {}
        for i in range(n):
            d[arr[i]] = i
        mn = n + 1
        mx = 0
        ans = ""
        for i in range(1, n + 1):
            mn = min(mn, d[i])
            mx = max(mx, d[i])
            if mx - mn + 1 == i:
                ans += "1"
            else:
                ans += "0"
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
