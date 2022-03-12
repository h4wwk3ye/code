#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 14/Nov/19 09:17:53 PM


import sys


def main():
    from collections import Counter

    ans = []
    for tc in range(int(input())):
        r, g = list(input().split())
        if len(r) < len(g):
            ans.append("NO")
            continue
        i, j = 0, 0
        while i < len(r) and j < len(g):
            if r[i] == g[j]:
                i += 1
                j += 1
            else:
                i += 1

        if j == len(g):
            ans.append("YES")
        else:
            ans.append("NO")
    print(*ans, sep="\n")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
