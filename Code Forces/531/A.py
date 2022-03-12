#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <09/Jan/2019 08:25:41 PM>


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
    n = int(input())
    sum = n * (n + 1) // 2
    print(0) if sum % 2 == 0 else print(1)


if __name__ == "__main__":
    main()
