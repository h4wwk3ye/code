#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <12/Jan/2019 12:59:17 PM>


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
    n = len(s)
    flag = 0
    mx, curr = 0, 0
    stack = []
    opening, closing = -1, -1
    for i in range(n):
        if s[i] == '[':
            opening = i
            break
    for i in range(n - 1, -1, -1):
        if s[i] == ']':
            closing = i
            break
    if opening == -1 or closing == -1:
        print(-1)
        return
    c_opening, c_closing = -1, -1
    for i in range(opening + 1, closing):
        if s[i] == ':':
            c_opening = i
            break
    for i in range(closing, opening, -1):
        if s[i] == ':':
            c_closing = i
            break
    if c_opening == -1:
        print(-1)
        return
    if closing <= opening:
        print(-1)
        return
    if c_opening == c_closing:
        print(-1)
        return

    check = False
    for i in range(c_opening + 1, c_closing):
        if s[i] == '|':
            mx += 1

    print(mx + 4)


if __name__ == "__main__":
    main()
