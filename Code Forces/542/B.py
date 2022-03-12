#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <24/Feb/2019 09:37:32 PM>


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
    d = {}

    for i in range(2*n):
        if arr[i] not in d:
            d[arr[i]] = []
        d[arr[i]].append(i)
    new = {}
    for key in sorted(d):
        new[key] = d[key]
    x, y = 0, 0
    # print(new)
    prev_x, prev_y = 0, 0
    for i in new:
        x += (abs(new[i][0]-prev_x))
        prev_x = new[i][0]
        y += (abs(new[i][1]-prev_y))
        prev_y = new[i][1]
    print(x+y)


if __name__ == "__main__":
    main()
