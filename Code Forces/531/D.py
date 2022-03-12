#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <09/Jan/2019 10:53:07 PM>


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
    s = list(input().strip())
    from collections import Counter
    d = Counter(s)
    count_0 = d['0'] - (n // 3)
    count_1 = d['1'] - (n // 3)
    count_2 = d['2'] - (n // 3)
    if count_0 > 0:
        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                count_0 -= 1
                if count_2 < 0:
                    count_2 += 1
                    s[i] = '2'
                elif count_1 < 0:
                    count_1 += 1
                    s[i] = '1'
            if count_0 == 0:
                break
    elif count_0 < 0:
        for i in range(n):
            if s[i] == '1' and count_1 > 0:
                count_0 += 1
                count_1 -= 1
                s[i] = '0'
            if s[i] == '2' and count_2 > 0:
                count_0 += 1
                count_2 -= 1
                s[i] = '0'
            if count_0 == 0:
                break
    if count_1 > 0:
        for i in range(n - 1, -1, -1):
            if s[i] == '1':
                count_1 -= 1
                count_2 += 1
                s[i] = '2'
            if count_1 == 0:
                break
    elif count_1 < 0:
        for i in range(n):
            if s[i] == '2':
                count_2 -= 1
                count_1 += 1
                s[i] = '1'
            if count_1 == 0:
                break
    print(*s, sep='')


if __name__ == "__main__":
    main()
