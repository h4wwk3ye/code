#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 02/Feb/20 07:47:17 PM


import sys


def main():
    for tc in range(int(input())):
        l = int(input())
        n = input()
        arr = []
        for i in n:
            if int(i) % 2 == 1:
                arr.append(i)
            if len(arr) == 2:
                break
        if len(arr) != 2:
            print(-1)
        else:
            print(*arr, sep="")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
