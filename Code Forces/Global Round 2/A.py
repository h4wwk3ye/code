#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <06/Apr/2019 05:10:59 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    x = arr[0]
    mx = 0
    for j in range(n-1, 0, -1):
        if arr[j] != x:
            mx = j
            break
    for i in range(1, n):
        if arr[i] != x:
            next = arr[i]
            curr = i
            break
    for i in range(n-1, curr, -1):
        if arr[i] != next:
            mx = max(mx, i-curr)
            break
    print(mx)


if __name__ == "__main__":
    main()
