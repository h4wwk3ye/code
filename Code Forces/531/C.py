#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <09/Jan/2019 09:22:59 PM>


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
    n, x, y = get_ints()
    arr = get_array()
    if x > y:
        print(n)
    else:
        count = 0
        for i in arr:
            if i <= x:
                count += 1
        count -= 1
        from math import ceil
        print(1 + count // 2)


if __name__ == "__main__":
    main()
