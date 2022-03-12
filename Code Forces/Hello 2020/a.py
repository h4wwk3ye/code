#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 04/Jan/20 05:38:16 PM


import sys


def main():
    n, m = get_ints()
    s = list(input().split())
    t = list(input().split())

    for tc in range(int(input())):
        y = int(input())
        y -= 1
        print(s[y % n] + t[y % m])


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
