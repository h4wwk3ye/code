#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 28/Dec/19 10:56:14 PM


import sys


def main():
    n = int(input())
    arr = get_array()
    from collections import deque

    d = deque()
    y = set(arr)
    for i in range(n):
        if arr[i] == 0 and i + 1 not in y:
            d.append(i + 1)
            y.add(i + 1)

    for i in range(1, n + 1):
        if i not in y:
            d.append(i)

    ans = [0] * n
    for i in range(n):
        if arr[i] != 0:
            ans[i] = arr[i]
        else:
            x = d.popleft()
            if x == i + 1:
                d.appendleft(x)
                x = d.pop()
            ans[i] = x
    print(*ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
