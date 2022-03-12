#!/usr/bin/env python3
# coding: utf-8
#Last Modified: 22/Feb/20 08:49:54 PM


import sys


def main():
    for tc in range(int(input())):
        n, m=get_ints()
        num=[1]*(n+10)
        den=[1]*(n+10)
        for i in range(m):
            x, y, k=get_ints()
            num[x]*=k
            den[y+1]*=k;
        t=0
        arr=[1]*(n+10)
        for i in range(1, n+1):
            arr[i] = arr[i-1] * (num[i]//den[i])
            t+=10*arr[i]
        ans = int(t//n)
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
