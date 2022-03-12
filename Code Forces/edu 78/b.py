#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 19/Dec/19 08:15:11 PM


import sys


def main():
    for tc in range(int(input())):
        a, b = get_ints()
        if a > b:
            a, b, = b, a

        ans = (b - a) // 3
        if a + ans * 2 != b:
            ans += 1
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
