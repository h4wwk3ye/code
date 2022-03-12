#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <27/Feb/2019 09:20:07 PM>


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
    d, v, w = get_ints()
    if d == 0 and v == 0:
        print(w)
    elif v == 0 and w == 0:
        print(d)
    elif w == 0 and d == 0:
        print(v)

    elif d == 0:
        print(v)
    elif v == 0:
        print(w)
    elif w == 0:
        print(d)

    else:
        print(1)


if __name__ == "__main__":
    main()
