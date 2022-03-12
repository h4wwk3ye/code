#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 30/Oct/19 07:10:44 PM


import sys


def main():
    for tc in range(int(input())):
        a, b = get_ints()
        if a > b:
            print("NO")
        elif a == b or (a % 2 == b % 2):
            print("YES")
        elif 2 * a <= b and a % 2 == 1:
            print("YES")
        else:
            print("NO")


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
