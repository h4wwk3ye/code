#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <15/Jan/2019 11:37:10 PM>


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
    n = int(input())
    s = input().strip()
    n %= (len(s) // 2 + 1)
    for k in range(n):
        x = []
        for i in range(len(s) // 2):
            x.append(s[i])
            x.append(s[-(i + 1)])
        if len(s) % 2 != 0:
            x.append(s[len(s) // 2])

    print(*x, sep='')


if __name__ == "__main__":
    main()
