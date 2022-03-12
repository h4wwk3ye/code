#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 19/Jan/20 07:18:58 PM


import sys


def main():
    n = int(input())
    x = n
    ans = 0
    while n != 0:
        ans += 1 / n
        n -= 1
    print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
