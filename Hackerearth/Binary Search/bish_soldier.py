#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <01/Mar/2019 12:08:43 AM>


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
    n = int(input())
    arr = [0]*(n+1)
    prefix = [0]*(n+1)
    for i in range(1, n+1):
        arr[i] = int(input())
        prefix[i] = prefix[i-1]+arr[i]

    for tc in range(int(input())):
        m = int(input())
        low = 1
        high = n
        while low < high:
            mid = (low+high)//2
            if (arr[mid] >= m):
                high = mid
            else:
                low = mid+1
        print(low, prefix[low])


if __name__ == "__main__":
    main()
