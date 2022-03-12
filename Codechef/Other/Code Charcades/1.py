#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <21/Jan/2019 09:26:33 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        n = int(input())
        if (n // 2) % 2 == 0:
            print(3)
        else:
            if n == 6:
                print(3)
            else:
                print(4)


if __name__ == "__main__":
    main()
