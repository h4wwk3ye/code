#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 17/Dec/19 08:49:32 PM


import sys


def main():
    x = "00"
    arr = []
    while len(x) <= 100:
        x = int(x)
        x += 60
        x = str(x)
        arr.append(x)
        print(x)

    # for tc in range(int(input())):
    #     s = list(input())


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
