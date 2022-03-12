#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <23/Jan/2019 10:40:44 PM>


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
    arr = get_array()
    arr.sort()
    x = arr[-1]
    if arr[-1] == arr[-2]:
        print(x, x)
        return
    for i in range(n - 2, 0, -1):
        if arr[i] == arr[i - 1]:
            print(x, arr[i])
            return
        elif x % arr[i] != 0:
            print(x, arr[i])
            return


if __name__ == "__main__":
    main()
