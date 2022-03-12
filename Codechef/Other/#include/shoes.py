#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 29/Mar/20 09:13:31 PM


import sys


def main():
    from collections import Counter

    for tc in range(int(input())):
        n, k = get_ints()
        s = input()
        d = Counter(s)
        flag = 1
        for i in d:
            if d[i] % 2 == 1:
                flag = 0
                break
            x = d[i] // 2
            if x > k:
                flag = 0
                break
        print("YES" if flag == 1 else "NO")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
