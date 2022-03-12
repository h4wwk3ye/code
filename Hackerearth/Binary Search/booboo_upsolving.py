#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <28/Feb/2019 01:23:22 AM>


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
    n, m = get_ints()
    arr = get_array()
    lo = max(arr)
    hi = sum(arr)

    while lo < hi:
        mid = (lo+hi)//2
        req = 1
        curr = 0
        for i in range(n):
            if (curr+arr[i]) <= mid:
                curr += arr[i]
            else:
                req += 1
                curr = arr[i]
        if req <= m:
            hi = mid
        else:
            lo = mid+1

    print(lo)


if __name__ == "__main__":
    main()
