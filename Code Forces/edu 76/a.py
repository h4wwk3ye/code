#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 13/Nov/19 08:07:04 PM


import sys


def main():
    for tc in range(int(input())):
        n, x, a, b = get_ints()
        a -= 1
        b -= 1
        if a > b:
            a, b = b, a
        while x > 0 and a > 0:
            x -= 1
            a -= 1
        while x > 0 and b < n - 1:
            x -= 1
            b += 1
        print(b - a)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
