#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <30/Mar/2019 08:59:30 PM>


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
    arr = [0]*n
    for i in range(n):
        arr[i] = input().strip()

    curr = 0
    mx = 0

    d = {}

    op = []

    for i in range(n):


if __name__ == "__main__":
    main()
