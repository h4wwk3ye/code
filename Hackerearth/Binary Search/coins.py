#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <10/Mar/2019 11:55:54 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys
#sys.stdin = open("input.txt", 'r')
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    from bisect import bisect, bisect_left
    n = int(input())
    arr = get_array()
    arr.sort()
    prefix = [0]*n
    prefix[0] = arr[0]
    for i in range(1, n):
        prefix[i] = (prefix[i-1]+arr[i])
    low, high = 0, prefix[-1]
    for mid in range(arr[-1]+1):
        l = bisect_left(arr, mid)
        r = bisect(arr, mid)

        if l == n:
            continue
        if l != 0:
            l -= 1

        if (prefix[l] == prefix[-1]-prefix[r-1]):
            print('YES')
            return
    print('NO')


if __name__ == "__main__":
    main()
