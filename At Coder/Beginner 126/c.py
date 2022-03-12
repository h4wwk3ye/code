#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <19/May/2019 05:51:38 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    #from math import log2
    n, k = get_ints()
    ans = 0
    for i in range(1, n + 1):
        curr = (1 / n)
        x = i
        while x < k:
            x *= 2
            curr *= (1 / 2)
        ans += curr
    print(ans)


if __name__ == "__main__":
    main()
