#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 04/Jan/20 06:31:46 PM


import sys


def main():
    n = int(input())
    arr = []
    chk = []
    cnt = 0
    for i in range(n):
        x = get_array()[1:]
        mn = x[0]
        mx = x[0]
        flag = 0
        for p in range(1, len(x)):
            j = x[p]
            mn = min(mn, j)
            mx = max(mx, j)
            if x[p] > x[p - 1]:
                flag = 1
        if flag == 0:
            arr.append(mn)
            chk.append(mx)
        else:
            cnt += 1

    chk.sort()
    from bisect import bisect

    # print(arr)
    # print(chk)

    ans = cnt * n

    # print(ans)
    for i in range(len(arr)):
        p = bisect(chk, arr[i])
        ans += len(arr) - p
        ans += cnt
        # print(len(arr) - p, ans)

    print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
