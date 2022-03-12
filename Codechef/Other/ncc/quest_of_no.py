#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <22/Feb/2019 12:11:14 AM>


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
    for tc in range(int(input())):
        l, r, a, b = get_ints()
        x = l % 9
        y = r % 9
        if x == 0:
            x = 9
        if y == 0:
            y = 9
        if y > x:
            arr = [i for i in range(x, y+1)]
            if a in arr and b not in arr:
                ans = 1
            elif a not in arr and b in arr:
                ans = 2
            else:
                ans = 0
        elif y == x:
            if a == x and b != x:
                ans = 1
            elif a != x and b == x:
                ans = 2
            else:
                ans = 0
        else:
            arr = [i for i in range(1, y+1)]
            arr += [i for i in range(x, 10)]
            if a in arr and b not in arr:
                ans = 1
            elif a not in arr and b in arr:
                ans = 2
            else:
                ans = 0
        if ans == 0:
            print('Draw')
        elif ans == 1:
            print('Onkar')
        else:
            print('Krushna')


if __name__ == "__main__":
    main()
