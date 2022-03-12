#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 15/Dec/19 03:23:06 PM


import sys


def main():
    n = int(input())
    s = list(input())

    f = 0
    for i in range(1, n):
        if s[i] != s[0]:
            f = 1
            break
    if f == 0:
        print(0)
        return
    ans = []
    for i in range(n - 1):
        if s[i] == "B" and s[i + 1] == "B":
            ans.append(i + 1)
            s[i] = "W"
            s[i + 1] = "W"
    for i in range(n - 2):
        if s[i] == "B" and s[i + 1] == "W":
            x = -1
            for j in range(i + 2, n):
                if s[j] == "B":
                    x = j
                    break
            if x == -1:
                break
            for j in range(i, x):
                ans.append(j + 1)
                s[j] = "W"
                s[j + 1] = "W"

    f = 0
    for i in range(n):
        if s[i] != "W":
            f = 1
            break
    if f:
        print(-1)
    else:
        print(len(ans))
        print(*ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
