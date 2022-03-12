#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <16/Mar/2019 04:26:14 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


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
    from bisect import bisect_left
    for tc in range(int(input())):
        m = int(input())
        print(bisect_left(arr, m))


if __name__ == "__main__":
    main()
