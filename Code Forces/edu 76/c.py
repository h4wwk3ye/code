#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 13/Nov/19 08:24:06 PM


import sys


def main():
    from collections import Counter
    from operator import itemgetter

    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        if n < 2:
            print(-1)
            continue
        d = {}
        ans = 10 ** 9
        for i in range(n):
            if arr[i] not in d:
                d[arr[i]] = i
            else:
                ans = min(ans, i - d[arr[i]] + 1)
                d[arr[i]] = i
        if ans == 10 ** 9:
            ans = -1
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
