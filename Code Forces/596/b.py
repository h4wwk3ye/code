#    !/usr/bin/env python3
#    encoding: UTF-8
#    Last Modified: 26/Oct/2019 04:57:40 PM


import sys


def main():
    for tc in range(int(input())):
        n, k, d = get_ints()
        di = {}
        arr = get_array()
        ans = 10 ** 9
        for i in range(d):
            if arr[i] in di:
                di[arr[i]] += 1
            else:
                di[arr[i]] = 1
        ans = len(di)
        # print(ans, di)
        for i in range(d, n):
            di[arr[i - d]] -= 1
            if di[arr[i - d]] == 0:
                del di[arr[i - d]]
            if arr[i] not in di:
                di[arr[i]] = 1
            else:
                di[arr[i]] += 1
            ans = min(ans, len(di))
            # print(ans, di)
        print(ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
