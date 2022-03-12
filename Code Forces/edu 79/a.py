#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 27/Dec/19 08:14:26 PM


import sys


def main():
    for tc in range(int(input())):
        r, g, b = get_ints()
        x = max(r, g, b)
        y = 0
        if x == r:
            y = g + b
        elif x == b:
            y = r + g
        else:
            y = r + b
        print("No" if y <= x - 2 else "Yes")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
