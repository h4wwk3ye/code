#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Feb/2019 07:14:44 PM>


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
    b, k = get_ints()
    arr = get_array()
    if k == 1:
        if arr[0] % 2 == 0:
            print('even')
        else:
            print('odd')
        return
    if b % 2 == 1:
        if k % 2 == 1:
            if arr[-1] % 2 == 1:
                print('even')
            else:
                print('odd')
        else:
            if arr[-1] % 2 == 0:
                print('odd')
            else:
                print('even')
    else:
        if arr[-1] % 2 == 0:
            print('even')
        else:
            print('odd')


if __name__ == "__main__":
    main()
