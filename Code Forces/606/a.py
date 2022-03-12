#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 14/Dec/19 10:38:42 PM


import sys


def main():
    arr = set()
    for i in range(1, 10):
        for j in range(1, 10):
            s = ""
            for k in range(1, 10):
                s += str(j)
                arr.add(int(s))
    arr = list(arr)
    arr.sort()
    from bisect import bisect_left

    for tc in range(int(input())):
        n = int(input())
        x = bisect_left(arr, n)
        if x < len(arr) and arr[x] == n:
            x += 1
        print(x)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
