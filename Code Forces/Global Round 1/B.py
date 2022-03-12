#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Feb/2019 07:43:30 PM>


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
    n, m, k = get_ints()
    arr = get_array()
    if k == n:
        print(n)
        return
    prefix = [0] * (n + 1)
    for i in range(1, n):
        prefix[i] = (arr[i] - arr[i - 1])
    print(prefix)


if __name__ == "__main__":
    main()
