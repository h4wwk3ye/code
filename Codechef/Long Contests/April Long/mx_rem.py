#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <14/Apr/2019 12:42:17 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    arr.sort()
    arr = list(set(arr))
    if len(arr) == 1:
        print(0)
        return
    print(arr[-2])


if __name__ == "__main__":
    main()
