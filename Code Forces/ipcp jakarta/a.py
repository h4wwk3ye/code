#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 27/Oct/2019 09:04:34 AM


import sys


def main():
    n = int(input())
    arr = get_array()
    for i in range(n):
        arr[i] -= 1
    ans = [0] * n
    for i in range(n):
        ans[i] = n - arr[i]
    print(*ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
