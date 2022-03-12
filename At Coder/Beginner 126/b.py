#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <19/May/2019 05:45:09 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    s = input()
    a = int(s[:2])
    b = int(s[2:])
    if (a > 12 and b > 12) or (a > 12 and b == 0) or (a == 0 and b > 12):
        print('NA')
        return

    if a == 0 and b <= 12 and b > 0:
        print("YYMM")
        return
    if b == 0 and a <= 12 and a > 0:
        print("MMYY")
        return

    if a <= 12 and b <= 12 and a > 0 and b > 0:
        print('AMBIGUOUS')
        return

    if a <= 12 and a != 0:
        print("MMYY")
        return
    if b <= 12 and b != 0:
        print("YYMM")
        return
    print('NA')


if __name__ == "__main__":
    main()
