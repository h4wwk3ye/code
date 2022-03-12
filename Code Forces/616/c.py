#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 02/Feb/20 09:00:40 PM


import sys


def main():
    from collections import deque

    for tc in range(int(input())):
        n, m, k = get_ints()
        arr = get_array()
        if k >= m - 1:
            mx = 0
            for i in range(m):
                mx = max(mx, arr[i])
            for i in range(n - 1, n - m - 1, -1):
                mx = max(mx, arr[i])
            print(mx)
        else:
            arr = deque(arr)
            while k != 0:
                a = arr.popleft()
                b = 10 ** 10
                if len(arr) != 0:
                    b = arr.pop()
                k -= 1
                m -= 1
                if a <= b and b != 10 ** 10:
                    arr.append(b)
                else:
                    arr.appendleft(a)

            while m > 1:
                a = arr.popleft()
                b = -1
                if len(arr) != 0:
                    b = arr.pop()
                k -= 1
                m -= 1
                if a >= b and b != -1:
                    arr.append(b)
                else:
                    arr.appendleft(a)
            a = arr.popleft()
            b = -1
            if len(arr) != 0:
                b = arr.pop()
            print(max(a, b))


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
