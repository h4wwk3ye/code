#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

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
    s = input().strip()
    upper = 0
    lower = 0
    for i in s:
        if i.islower() == True:
            lower += 1
        elif lower > 0:
            lower -= 1
            upper += 1
    print(upper)


if __name__ == "__main__":
    main()
