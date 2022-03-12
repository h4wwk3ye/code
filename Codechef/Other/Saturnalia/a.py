#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 15/Nov/19 09:34:39 PM


import sys


def main():
    for tc in range(int(input())):
        d = {}
        s = input()
        for i in range(len(s)):
            if i not in d:
                d[i] = []
            d[i].append(i)
        d = sorted(d.items())
        ans = 0
        c = ""
        for i in d:
            if len(d[i][1]) > 1:
                if d[i][1][-1] - d[i][1][0] > ans:
                    ans = d[i][1][-1] - d[i][1][0]
                    c = i
        print(c, ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
