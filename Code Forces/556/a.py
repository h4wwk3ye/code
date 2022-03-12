#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <29/Apr/2019 08:09:38 PM>


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
    n, m, r = get_ints()
    buy = get_array()
    buy.sort()
    sell = get_array()
    sell.sort(reverse=True)
    if (buy[0] >= sell[-1]):
        print(r)
        return
    else:
        x = r // buy[0]
        y = x * sell[0]
        print(r - x * buy[0] + y)


if __name__ == "__main__":
    main()
