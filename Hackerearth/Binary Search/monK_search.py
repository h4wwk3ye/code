#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Mar/2019 01:00:17 PM>


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
    arr = get_array()
    arr.sort()
    for tc in range(int(input())):
        t, x = get_ints()
        if t == 0:
            low = 0
            high = n-1
            while low < high:
                mid = (low+high)//2
                if arr[mid] >= x:
                    high = mid
                else:
                    low = mid+1
            if low == n-1:
                if arr[-1] >= x:
                    print(1)
                else:
                    print(0)
            else:
                print(n-low)
        else:
            low = 0
            high = n-1
            while low < high:
                mid = (low+high)//2
                if arr[mid] > x:
                    high = mid
                else:
                    low = mid+1
            if low == n-1:
                if arr[-1] > x:
                    print(1)
                else:
                    print(0)
            else:
                print(n-low)


if __name__ == "__main__":
    main()
