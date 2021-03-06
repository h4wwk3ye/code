#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <06/May/2019 12:26:27 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


# ///==========MAIN=============///

inf = float('inf')


def main():
    n, h, m = get_ints()
    arr = [inf] * n
    for tc in range(m):
        l, r, x = get_ints()
        l -= 1
        r -= 1
        for i in range(l, r + 1):
            arr[i] = min(arr[i], x)
    ans = 0
    for i in arr:
        if i == inf:
            ans += (h**2)
        else:
            ans += (i**2)
    print(ans)


if __name__ == "__main__":
    main()
