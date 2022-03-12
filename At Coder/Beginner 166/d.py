#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 03/May/20 05:49:15 PM


import sys


def main():
    arr = []
    for i in range(-(10 ** 4), 10 ** 4):
        arr.append((pow(i, 5), i))
    x = int(input())
    from bisect import bisect_left

    ans = False
    A, B = -1, -1
    for i in arr:
        c = i[0] - x
        idx = bisect_left(arr, (c, -(10 ** 20)))

        if idx < len(arr) and arr[idx][0] == c:
            ans = True
            A = i[1]
            B = arr[idx][1]
            break
    print(A, B)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
