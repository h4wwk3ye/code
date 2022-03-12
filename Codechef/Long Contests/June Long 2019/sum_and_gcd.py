#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <09/Jun/2019 02:38:36 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior

from __future__ import division, print_function
import sys
py2 = round(0.5)
if py2 == 1:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    from math import gcd
    for tc in range(int(input())):
        n = int(input())
        arr = sorted(list(set(get_array())))
        n = len(arr)
        if n == 1:
            print(2 * arr[0])
            continue
        if n == 2:
            print(arr[0] + arr[1])
            continue

        x = arr[0]
        for i in range(n - 2):
            x = gcd(x, arr[i])

        print(max(arr[-1] + gcd(x, arr[-2]), arr[-2] + gcd(arr[-1], x)))


if __name__ == "__main__":
    main()
