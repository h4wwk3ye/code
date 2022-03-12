#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 21/Dec/19 04:53:44 PM


import sys


def main():
    from collections import Counter
    from operator import itemgetter

    n, m = get_ints()
    a = get_array()
    b = get_array()
    a.sort()
    b.sort()
    d1 = Counter(a)
    d2 = Counter(b)
    x = sorted(d1.items())
    y = sorted(d2.items())

    def check(p, q):
        d = max(p, q) - min(p, q)
        arr = [(i + d)%m for i in a]
        arr.sort()
        return arr==b
    ans= 10**9
    for i in x:
        for j in y:
            if i[1] == j[1]:
                if (check(i[0], j[0]))==True:
                    ans = min(ans, max(i[0], j[0]) - min(i[0], j[0]))
        break
    print(ans)

get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
