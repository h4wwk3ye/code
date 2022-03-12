#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <26/May/2019 06:05:50 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    a, p = get_ints()
    p += a * 3
    print(p // 2)


if __name__ == "__main__":
    main()
