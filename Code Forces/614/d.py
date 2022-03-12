#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 19/Jan/20 11:14:20 PM


import sys


def main():
    x0, y0, ax, ay, bx, by = get_ints()
    points = []
    points.append((x0, y0))
    xs, ys, t = get_ints()
    # cin >> xs >> ys >> t;

    x = x0
    y = y0

    def manhattan(x1, y1, x2, y2):
        return abs(x1 - x2) + abs(y1 - y2)

    for i in range(1, 100):
        x = ax * x + bx
        y = ay * y + by
        points.append((x, y))

    ans, curr = 0, 0
    for i in range(len(points)):
        T = t
        XS = xs
        YS = ys
        curr = 0
        f = 1
        for j in range(i, len(points)):
            x = points[j][0]
            y = points[j][1]
            dist = manhattan(XS, YS, x, y)
            T -= dist
            XS = x
            YS = y
            curr += 1
            if T < 0:
                ans = max(ans, curr - 1)
                f = 0
                break

        if f:
            ans = max(ans, curr)

    points.reverse()
    for i in range(len(points)):
        T = t
        XS = xs
        YS = ys
        curr = 0
        f = 1
        for j in range(i, len(points)):
            x = points[j][0]
            y = points[j][1]
            dist = manhattan(XS, YS, x, y)
            T -= dist
            curr += 1
            XS = x
            YS = y
            if T < 0:
                ans = max(ans, curr - 1)
                f = 0
                break

        if f:
            ans = max(ans, curr)

    print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
