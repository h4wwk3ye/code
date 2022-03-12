#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 28/Dec/19 10:44:47 PM


import sys


def main():
    from math import ceil

    for tc in range(int(input())):
        n, k = get_ints()
        p = n // k
        y = p * k
        if y == n:
            print(n)
            continue

        ans = ceil(k / 2) * p + (k // 2 * (p + 1))
        print(min(n, ans))


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
