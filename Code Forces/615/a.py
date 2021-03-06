#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 22/Jan/20 09:50:48 PM


import sys


def main():
    for tc in range(int(input())):
        a, b, c, n = get_ints()
        x = a + b + c + n
        if x % 3 != 0:
            print("NO")
        else:
            y = max(a, b, c)
            if (x // 3) >= y:
                print("YES")
            else:
                print("NO")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
