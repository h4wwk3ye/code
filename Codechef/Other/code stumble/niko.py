#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <16/Jan/2019 05:41:36 PM>


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
    n, k = get_ints()
    arr = [0] * n
    for i in range(n):
        arr[i] = get_array()
    for i in range(n):
        for j in len(arr[i]):
            arr[i][j] *= -1
    for i in range(n):
        front = 0
        curr_mx = 0
        for j in range(len(arr)):
            if curr_mx + arr[i][j]


if __name__ == "__main__":
    main()
