#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <07/Jun/2019 06:29:16 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    x, y, z = get_ints()
    if x - y > z:
        print('+')
    elif x - y == 0 and z == 0:
        print(0)
    elif abs(x - y) > z:
        print('-')
    else:
        print('?')


if __name__ == "__main__":
    main()
