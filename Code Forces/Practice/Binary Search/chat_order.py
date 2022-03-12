#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <09/Mar/2019 11:00:32 PM>


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
    from collections import OrderedDict
    d = OrderedDict()
    n = int(input())
    arr = [0]*n
    for i in range(n):
        arr[i] = input().strip()
    for i in reversed(arr):
        if i not in d:
            d[i] = 1
    print(*d, sep='\n')


if __name__ == "__main__":
    main()
