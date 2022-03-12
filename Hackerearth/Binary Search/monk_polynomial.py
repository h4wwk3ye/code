#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Mar/2019 12:41:22 PM>


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


def main():
    for tc in range(int(input())):
        a, b, c, k = get_ints()
        c = k-c
        low = 0
        high = int(10**6)
        while low < high:
            mid = (low+high)//2
            if (a*(mid**2)+b*(mid)) >= c:
                high = mid
            else:
                low = mid+1
        print(low)


if __name__ == "__main__":
    main()
