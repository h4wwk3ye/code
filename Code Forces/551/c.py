#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <13/Apr/2019 09:15:00 PM>


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
    arr = list(input())
    print(arr)


if __name__ == "__main__":
    main()
