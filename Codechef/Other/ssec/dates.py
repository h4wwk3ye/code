#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 15/Sep/20 11:23:45 AM


import sys


def main():
    n = int(input())
    arr = [0] * n
    for i in range(n):
        arr[i] = input()
    from functools import cmp_to_key

    def compare(x, y):
        a, b, c = map(int, x.split("/"))
        d, e, f = map(int, y.split("/"))

        if c < f:
            return -1
        elif c > f:
            return 1

        if b < e:
            return -1
        elif b > e:
            return 1

        if a < d:
            return -1
        elif a > d:
            return 1

        return 0

    arr.sort(key=cmp_to_key(compare))
    print(*arr, sep='\n')


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
