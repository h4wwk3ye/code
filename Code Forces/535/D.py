#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <23/Jan/2019 09:18:55 PM>


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
    if n == 1:
        print(0)
        print(*s, sep='')
        return
    if n == 2:
        if s[0] != s[1]:
            print(0)
            print(*s, sep='')
            return
        if s[0] == s[1]:
            print(1)
            if s[0] == 'R':
                print('RG')
                return
            elif s[0] == 'G':
                print('GB')
                return
            elif s[0] == 'B':
                print('BR')
                return

    mn, count = inf, 0
    for i in range(n - 2):
        if s[i] == s[i + 1]:
            count += 1
            if s[i + 1] == s[i + 2]:
                if s[i] == 'R':
                    s[i + 1] = 'G'
                elif s[i] == 'G':
                    s[i + 1] = 'B'
                elif s[i] == 'B':
                    s[i + 1] = 'G'
            else:
                if (s[i] == 'R' or s[i] == 'G') and (s[i + 2] == 'R' or s[i + 2] == 'G'):
                    s[i + 1] = 'B'
                elif (s[i] == 'R' or s[i] == 'B') and (s[i + 2] == 'R' or s[i + 2] == 'B'):
                    s[i + 1] = 'G'
                elif (s[i] == 'B' or s[i] == 'G') and (s[i + 2] == 'B' or s[i + 2] == 'G'):
                    s[i + 1] = 'R'
    if s[-1] == s[-2]:
        count += 1
        if s[-2] == 'R':
            s[-1] = 'G'

        elif s[-2] == 'G':
            s[-1] = 'B'

        elif s[-2] == 'B':
            s[-1] = 'R'
    print(count)
    print(*s, sep='')


if __name__ == "__main__":
    main()
