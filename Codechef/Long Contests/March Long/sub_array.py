#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <01/Mar/2019 11:39:31 PM>


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
    for tc in range(int(input())):
        n, k = get_ints()
        arr = get_array()
        arr.sort()
        print(arr)


if __name__ == "__main__":
    main()
