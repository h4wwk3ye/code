#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 26/Oct/2019 04:43:24 PM


import sys


def main():
    a, b = input().split()
    if a == b:
        print(a + "0", b + "1")
    elif int(a) + 1 == int(b):
        print(a + "9", b + "0")
    elif a == "9" and b == "1":
        print(99, 100)
    else:
        print(-1)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
