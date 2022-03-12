#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

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
    s = input().strip()
    arr = get_array()
    h, a, r, d = 0, 0, 0, 0
    for i in s:
        if h == 0:
            if i == 'h':
                h = 1
        elif a == 0:
            if i == 'a':
                a = 1
        elif r == 0:
            if i == 'r':
                r = 1
        elif d == =0:
            if i == 'd':
                d = 1
    if h != 1 or r != 1 or a != 1 or d != 1:
        print(0)
        return
    from collections import defaultdict
    d = defaultdict(list)
    a, b, c, d = 0, 0, 0, 0

    for i in range(n):
        if s[i] == 'h':
            d[1].append(arr[i])
            a +=
        elif s[i] == 'a':
            d[2].append(arr[i])
        elif s[i] == 'r':
            d[3].append(arr[i])
        elif s[i] == 'd':
            d[4].append(arr[i])


if __name__ == "__main__":
    main()
