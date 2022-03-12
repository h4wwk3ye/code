#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/602/B
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
    l, r = 0, 0
    for i in range(n):
        l = max(l, d.get(arr[i]+2, -1)+1, d.get(arr[i]-2, -1)+1)
        r = max(r, i-l+1)
        d[arr[i]] = i
    print(r)


if __name__ == "__main__":
    main()
