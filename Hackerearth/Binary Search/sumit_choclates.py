#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Mar/2019 12:30:03 AM>


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
    prefix = [0]*(n+1)
    for i in range(1, n):
        arr[i] += arr[i-1]
    from bisect import bisect_left as bisect
    for tc in range(int(input())):
        print(bisect(arr, int(input()))+1)


if __name__ == "__main__":
    main()
