#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <02/Jan/2019 02:38:52 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.codechef.com/PRACTICE/problems/DELISH
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream

inf = float("inf")
mod = 1000000007


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        mx, curr_mx = arr[0], arr[0]
        for i in range(1, n):
            curr_mx = max(arr[i], curr_mx + arr[i])
            mx = max(curr_mx, mx)
        mn, curr_mn = arr[0], arr[0]
        for i in range(1, n):
            curr_mn = min(arr[i], curr_mn + arr[i])
            mn = min(curr_mn, mn)
        print(mx - mn)


if __name__ == "__main__":
    # fast_io()
    main()
