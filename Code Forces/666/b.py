#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 30/Aug/20 08:44:48 PM


import sys


def main():
    n = int(input())
    arr = get_array()
    arr.sort()

    ans = 10 ** 18

    r = 10 ** 5 // n

    for i in range(1, r + 1):
        curr = 0
        x = 0
        for j in arr:
            curr += abs(j - i ** x)
            x += 1
        ans = min(ans, curr)

    print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
