#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 27/Mar/20 06:27:48 PM


# import resource, sys
import sys

# resource.setrlimit(resource.RLIMIT_STACK, (2 ** 29, -1))
sys.setrecursionlimit(10 ** 6)


def main():
    n, k = get_ints()
    


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
