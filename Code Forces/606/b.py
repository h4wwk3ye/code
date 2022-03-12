#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 14/Dec/19 10:47:04 PM


import sys

from collections import Counter
from operator import itemgetter


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        d = Counter(arr)
        d = sorted(d.items(), reverse=True)
        x = Counter(arr)
        ans = 0
        for i in d:
            if i[0] % 2 == 0:
                p = i[0]
                while p % 2 == 0:
                    ans += 1
                    p >>= 1
                    if p in x:
                        break
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
