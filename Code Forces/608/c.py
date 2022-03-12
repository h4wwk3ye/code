#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 15/Dec/19 10:01:11 PM


import sys


def main():
    n, sx, sy = get_ints()
    d = [0] * 4
    arr = []

    for i in range(n):
        x, y = get_ints()
        x -= sx
        y -= sy
        arr.append((x, y))
        if y >= 1:
            d[0] += 1
        if x <= -1:
            d[1] += 1
        if y <= -1:
            d[2] += 1
        if x >= 1:
            d[3] += 1

    ans = max(d)
    print(ans)
    if d[0] == ans:
        print(sx, sy + 1)
    elif d[1] == ans:
        print(sx - 1, sy)
    elif d[2] == ans:
        print(sx, sy - 1)
    else:
        print(sx + 1, sy)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
