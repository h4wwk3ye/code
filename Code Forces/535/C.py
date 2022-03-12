#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <23/Jan/2019 09:00:12 PM>


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
    s = input().strip()
    from math import ceil
    x = ceil(n / 3)
    r1 = [['R'], ['G'], ['B']] * x
    r2 = [['R'], ['B'], ['G']] * x
    g1 = [['G'], ['B'], ['R']] * x
    g2 = [['G'], ['R'], ['B']] * x
    b1 = [['B'], ['G'], ['R']] * x
    b2 = [['B'], ['R'], ['G']] * x
    mn = inf
    count = 0
    for i in range(n):
        if s[i] != r1[i][0]:
            count += 1
    if mn > count:
        mn = count
        flag = 1

    if mn == 0:
        print(0)
        print(s)
        return

    count = 0
    for i in range(n):
        if s[i] != r2[i][0]:
            count += 1
    if mn > count:
        mn = count
        flag = 2
    if mn == 0:
        print(0)
        print(s)
        return

    count = 0
    for i in range(n):
        if s[i] != g1[i][0]:
            count += 1
    if mn > count:
        mn = count
        flag = 3
    if mn == 0:
        print(0)
        print(s)
        return

    count = 0
    for i in range(n):
        if s[i] != g2[i][0]:
            count += 1
    if mn > count:
        mn = count
        flag = 4
    if mn == 0:
        print(0)
        print(s)
        return

    count = 0
    for i in range(n):
        if s[i] != b1[i][0]:
            count += 1
    if mn > count:
        mn = count
        flag = 5
    if mn == 0:
        print(0)
        print(s)
        return

    count = 0
    for i in range(n):
        if s[i] != b2[i][0]:
            count += 1
    if mn > count:
        mn = count
        flag = 6
    if mn == 0:
        print(0)
        print(s)
        return
    print(mn)
    if flag == 1:
        for i in range(n):
            print(r1[i][0], end='')
        print()
        return

    if flag == 2:
        for i in range(n):
            print(r2[i][0], end='')
        print()
        return

    if flag == 3:
        for i in range(n):
            print(g1[i][0], end='')
        print()
        return

    if flag == 4:
        for i in range(n):
            print(g2[i][0], end='')
        print()
        return

    if flag == 5:
        for i in range(n):
            print(b1[i][0], end='')
        print()
        return

    if flag == 6:
        for i in range(n):
            print(b2[i][0], end='')
        print()
        return


if __name__ == "__main__":
    main()
