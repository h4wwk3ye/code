#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <23/Jan/2019 09:44:04 PM>


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
    n, m = get_ints()
    arr = get_array()
    subsets = [0] * m
    for i in range(m):
        u, v = get_ints()
        subsets[i] = ((u, v))
    mx = -1 * inf
    mn = inf
    maximum = [0] * 306
    minimum = [0] * 306
    #import bisect
    for i in range(n):
        if arr[i] >= mx:
            mx = arr[i]
            maximum[i + 1] += 1
        if arr[i] <= mn:
            mn = arr[i]
            minimum[i + 1] += 1

    if len(maximum) == 1 and len(minimum) == 1:
        print(mx - mn)
        print(0)
        print(*arr)
        return

    index = -1
    p = max(maximum)
    maxi = []
    for i in range(1, n + 1):
        if p == maximum[i]:
            maxi.append(i)
    other = [0] * len(maxi)
    for i in range(m):
        print(subsets[i])


if __name__ == "__main__":
    main()
