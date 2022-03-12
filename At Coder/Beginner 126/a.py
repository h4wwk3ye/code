#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <19/May/2019 05:33:27 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    n, k = get_ints()
    s = list(input())
    s[k - 1] = s[k - 1].lower()
    print(*s, sep='')


if __name__ == "__main__":
    main()
