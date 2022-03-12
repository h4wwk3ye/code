#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 12/Dec/19 08:05:09 PM


import sys


def main():
    for tc in range(int(input())):
        s = input()
        f = 0
        d = {}
        x, y = 0, 0
        ans = []
        l, r, u, d = 0, 0, 0, 0
        for i in range(len(s)):
            if s[i] == "U":
                u += 1
            elif s[i] == "D":
                d += 1
            elif s[i] == "L":
                l += 1
            else:
                r += 1
        op = []

        if l + r <= 1 or l == 0 or r == 0:
            if u == 0 or d == 0:
                print(0)
                print()
            else:
                print(2)
                print("UD")
        elif u + d <= 1 or u == 0 or d == 0:
            if l == 0 or r == 0:
                print(0)
                print()
            else:
                print(2)
                print("LR")
        else:
            i = min(d, u)
            while i > 0:
                op.append("D")
                i -= 1
            i = min(l, r)
            while i > 0:
                op.append("R")
                i -= 1
            i = min(d, u)
            while i > 0:
                op.append("U")
                i -= 1
            i = min(l, r)
            while i > 0:
                op.append("L")
                i -= 1
            print(len(op))
            print(*op, sep="")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
