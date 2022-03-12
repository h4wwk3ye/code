#!/usr/bin/env python3
# coding: utf-8
#Last Modified: 08/Mar/20 10:37:04 PM


import sys


def main():
    for tc in range(int(input())):
        n, k = get_ints()
        x = n
        cnt = 0
        while x:
            r = x%3
            cnt +=r
            x//=3
        if(k >= cnt):
            print("YES")
        else:
            print("NO")

    

get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
