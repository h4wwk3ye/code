#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <05/Feb/2019 06:31:01 PM>


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
    n = int(input())
    arr = get_array()
    ans = 0
    s = set()
    for i in range(n):
        if arr[i] == i + 1:
            ans += 1
        else:
            s.add(arr[i])
    print(ans + len(s) // 2)


if __name__ == "__main__":
    main()
