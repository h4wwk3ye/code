#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 16/Nov/19 05:44:05 PM


import sys


def main():
    from math import factorial, sqrt
    from itertools import permutations

    n = int(input())
    arr = [get_array() for _ in range(n)]

    x = [i for i in range(n)]
    p = list(permutations(x))

    def dis(x1, y1, x2, y2):
        return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

    distance = 0
    for j in p:
        for i in range(1, len(j)):
            distance += dis(
                arr[j[i]][0], arr[j[i]][1], arr[j[i - 1]][0], arr[j[i - 1]][1]
            )
    print(distance / factorial(n))


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
