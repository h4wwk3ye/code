#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <28/Feb/2019 08:29:44 PM>


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
    n, q = get_ints()
    arr = get_array()
    prefix = [0]*(n+1)

    for i in range(1, n+1):
        prefix[i] = (prefix[i-1]+arr[i-1])

    queries = get_array()

    for i in queries:
        low = 1
        high = n
        while low < high:
            mid = (low+high)//2
            if prefix[mid] >= i:
                high = mid
            else:
                low = mid+1
        print(low)


if __name__ == "__main__":
    main()
