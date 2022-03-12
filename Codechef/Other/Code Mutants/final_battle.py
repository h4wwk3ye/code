#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <27/Feb/2019 09:54:45 PM>


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
    f = input().strip()
    s = input().strip()
    a, b, c, d = get_ints()
    i = 0
    cost = 0
    while i < n:
        if f[i] == s[i]:
            i += 1
            continue
        if (f[i] == '1' or f[i] == '2') and (s[i] == '1' or s[i] == '2'):
            cost += min(d, a)
        elif (f[i] == '3' or f[i] == '2') and (s[i] == '3' or s[i] == '2'):
            cost += min(d, b)
        elif (f[i] == '1' or f[i] == '3') and (s[i] == '1' or s[i] == '3'):
            cost += min(d, c)
        i += 1
    print(cost)
cpl

if __name__ == "__main__":
    main()
