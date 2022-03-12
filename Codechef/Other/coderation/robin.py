#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <09/Apr/2019 12:51:16 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        b = int(input())
        if b == 0:
            print(10)
            continue
        if b % 10 != 0:
            b = (b//10)*10+10
        a = b
        l = 0
        while a != 0:
            a //= 10
            l += 1
        if l == 2:
            print(b)
        elif l == 3:
            if b % 100 == 0:
                print(b+10)
            else:
                print(b)
        else:
            if b % 1000 == 0 or b % 100 == 0:
                print(b+10)
            else:
                print(b)


if __name__ == "__main__":
    main()
