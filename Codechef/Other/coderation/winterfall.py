#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <09/Apr/2019 12:52:58 AM>


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
    for tc in range(int(input())):
        m, n, p, q = get_ints()
        print((m-p+1)*(n-q+1))


if __name__ == "__main__":
    main()
