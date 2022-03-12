#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Mar/2019 12:15:57 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

from typing import Any

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    x = arr[-1]
    for i in range(n):  # type: Any
        if arr[i] != x:
            index = i
    print(index+1)
    # print(n-index)


if __name__ == "__main__":
    main()
