#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Feb/2019 09:53:36 PM>


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
    mx = 2 * (10**6) + 5
    arr = [0] * mx
    for i in range(1, mx):
        arr[i] += arr[i - 1]
        p = hex(i)[2:]
        for j in p:
            q = ord(j)
            if q >= 97 and q <= 122:
                arr[i] += 1
    for tc in range(int(input())):
        l, r = get_ints()
        print(arr[r] - arr[l - 1])


if __name__ == "__main__":
    main()
