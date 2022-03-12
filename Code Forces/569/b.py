#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <22/Jun/2019 01:07:08 AM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    n = int(input())
    arr = get_array()
    s, l = [], []
    z = []
    ans = [0] * n
    for i in range(n):
        if arr[i] < 0:
            s.append((arr[i], i))
        elif arr[i] > 0:
            l.append((arr[i], i))
        else:
            z.append((arr[i], i))
    l.sort()
    le = len(s) + len(z)
    if len(l) == 0:
        if le % 2 == 1:
            if len(z) % 2 == 0:
                for i in range(len(s)):
                    ans[s[i][1]] = -s[i][0] - 1
                for i in range(len(z)):
                    ans[z[i][1]] = -1
                print(*ans)
                return
            else:
                if len(s) == 0:
                    print(*arr)
                    return
                s.sort()
                ans[s[0][1]] = -s[0][0] - 1
                for i in range(1, len(s)):
                    ans[s[i][1]] = s[i][0]
                for i in range(len(z)):
                    ans[z[i][1]] = -1
                print(*ans)
                return
            return
        else:
            for i in range(len(s)):
                ans[s[i][1]] = s[i][0]
            for i in range(len(z)):
                ans[z[i][1]] = -1
            print(*ans)
            return
    for i in range(len(s)):
        ans[s[i][1]] = s[i][0]
    for i in range(len(z)):
        ans[z[i][1]] = -1
    for i in range(len(l) - 1):
        ans[l[i][1]] = -l[i][0] - 1
        le += 1
    if le % 2 == 1:
        ans[l[-1][1]] = -l[-1][0] - 1
    else:
        ans[l[-1][1]] = l[-1][0]
    print(*ans)


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
