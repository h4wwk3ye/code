#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 13/Nov/19 08:15:24 PM


import sys


def main():
    for tc in range(int(input())):
        x, y = get_ints()
        if x == 1 and y > x:
            print("NO")
            continue
        if x <= 3 and y > 3:
            print("NO")
            continue
        print("YES")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
