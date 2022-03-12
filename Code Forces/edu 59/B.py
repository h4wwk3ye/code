#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <26/Jan/2019 09:25:54 PM>


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
    arr = [-1, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    for tc in range(int(input())):
        k, x = get_ints()
        print(arr[x] + (9 * (k - 1)))


if __name__ == "__main__":
    main()
