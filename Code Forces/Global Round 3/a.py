#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Jun/2019 08:15:39 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    a, b, c = get_ints()
    ans = min(a, b, c) * 4
    x = min(a, b, c)
    if (c - x) > 0:
        ans += 2 * (c - x)
    a -= x
    b -= x
    if (a == b):
        ans += 2 * a
    else:
        ans += 2 * min(a, b) + 1
    print(ans)


if __name__ == "__main__":
    main()
