#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 04/Jan/20 07:53:35 PM


import sys


def main():
    n, m = get_ints()
    ans = 0
    x = (n * (n + 1)) // 2

    f = 0
    if n & 1:
        f = 1
    j = 0
    for i in range(1, n):
        if i == 1:
            ans += x
        else:
            ans += (x - j) * ((x // 2) - 1)

        if f:
            j += 1
        else:
            j += 2
        f = 1 ^ f

    # ans += x

    print(ans * (n + 2) // 2 % m)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
