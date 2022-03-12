#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 19/Dec/19 07:22:51 PM


import sys


def main():
    for tc in range(int(input())):
        s = input()
        x, y = get_ints()
        arr = [0] * (len(s) + 1)
        p, q = 0, 0
        for i in range(len(s)):
            if s[i] == "A":
                p = i + 1
            if s[i] == "B":
                q = i + 1
        t = 1
        for i in range(p, len(s) + 1, x):
            arr[i] = t
            t += 1
        f = 0
        t = 1
        for i in range(q, 0, -y):
            if arr[i] == t:
                f = 1
            t += 1
        print("safe" if f == 0 else "unsafe")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
