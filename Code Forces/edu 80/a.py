#!/usr/bin/env python3
# coding: utf-8
#Last Modified: 14/Jan/20 08:07:12 PM


import sys


def main():
    for tc in range(int(input())):
        n, d=get_ints()


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
