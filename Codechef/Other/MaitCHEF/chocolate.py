#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 09/Nov/19 03:44:41 PM


import sys


def main():
    for tc in range(int(input())):
        z = int(input())
        b = bin(z)[2:]

        mn = ""
        mx = "1"
        for i in range(len(b)):
            if b[i] == "0":
                mn += "1"
            else:
                mn += "0"
            mx += "0"

        print(int(mn, 2), int(mx, 2))


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
