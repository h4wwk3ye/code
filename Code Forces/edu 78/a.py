#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 19/Dec/19 08:12:17 PM


import sys

from collections import Counter


def main():
    for tc in range(int(input())):
        p = list(input())
        p.sort()
        s = input()
        f = 0
        for i in range(len(s) - len(p) + 1):
            x = s[i : i + len(p)]
            if sorted(x) == p:
                f = 1
                break
        print("YES" if f else "NO")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
