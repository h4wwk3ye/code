#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 05/Jan/20 05:16:25 PM


import sys


def main():
    n, k = get_ints()
    arr = get_array()
    from collections import Counter
    from operator import itemgetter

    d = Counter(arr)
    d = sorted(d.items(), key=itemgetter(1))

    ans = 0
    i = 0
    while ans < k and i < len(d):
        ans += d[i][1]
        i += 1

    print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
