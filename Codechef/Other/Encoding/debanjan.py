#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 30/Oct/19 07:04:55 PM


import sys


def main():
    for tc in range(int(input())):
        n, k = get_ints()
        arr = get_array()
        s = sum(arr)
        print("YES" if s <= k else "NO")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
