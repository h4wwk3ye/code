#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Feb/2019 11:03:33 PM>


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
    s = input().strip()
    t = input().strip()
    cnt1, cnt2, cnt3, cnt4 = 0, 0, 0, 0
    v1, c1, v2, c2 = [], [], [], []
    for p in range(len(s)):
        i = s[p]
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u':
            cnt1 += 1
            v1.append(p)
        else:
            cnt2 += 1
            c1.append(p)
    for p in range(len(t)):
        i = t[p]
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u':
            cnt3 += 1
            v2.append(p)
        else:
            cnt4 += 1
            c2.append(p)
    if cnt1 == cnt3 and cnt2 == cnt4 and v1 == v2 and c1 == c2:
        print('YES')
    else:
        print('NO')


if __name__ == "__main__":
    main()
