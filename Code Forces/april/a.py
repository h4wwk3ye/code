#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Apr/2019 08:47:59 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()

    if arr == sorted(arr):
        print(n)
        return

    n //= 2

    if n == 0:
        print(1)
        return

    x = arr[:n]
    y = arr[n:]
    if x == sorted(x) or y == sorted(y):
        print(n)
        return

    n //= 2

    if n == 0:
        print(1)
        return

    x1 = x[:n]
    x2 = x[n:]
    y1 = y[:n]
    y2 = y[n:]

    if x1 == sorted(x1) or x2 == sorted(x2) or y2 == sorted(y2) or y1 == sorted(y1):
        print(n)
        return

    n //= 2

    if n == 0:
        print(1)
        return

    x11 = x1[:n]
    x12 = x1[n:]
    x21 = x2[:n]
    x22 = x2[n:]

    y11 = y1[:n]
    y12 = y1[n:]
    y21 = y2[:n]
    y22 = y2[n:]

    if x11 == sorted(x11) or x22 == sorted(x22) or x21 == sorted(x21) or x12 == sorted(x12):
        print(n)
        return

    if (y11) == sorted(y11) or y12 == sorted(y12) or y21 == sorted(y21) or y22 == sorted(y22):
        print(n)
        return

    n //= 2

    if n == 0:
        print(1)
        return


if __name__ == "__main__":
    main()
