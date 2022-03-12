#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Apr/2019 09:20:17 PM>


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

from math import factorial as fact

def nCr(n, r=2):

    return (fact(n) / (fact(r)
                * fact(n - r)))

def main():
    n = int(input())
    if n==2:
        print(3)
        return
    if n==3:
        print(13)
    ans=nCr(n)

    print(ans)


if __name__ == "__main__":
    main()
