#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <22/Jan/2019 09:52:36 PM>


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


def check(i, j, n):
    if i < 0 or j == n:
        return False
    return True


def main():
    s = list(input().strip())
    n = len(s)
    count = 0
    i = 0
    x, y = 0, 0
    while i < n - 1:
        if s[i] == s[i + 1] and (s[i] != -1 and s[i + 1] != -1):
            count += 1
            s[i] = -1
            s[i + 1] = -1
            if x == 0 and y == 0:
                x, y = i - 1, i + 2
            while check(x, y, n) == True and s[x] == s[y] and (s[x] != -1 and s[y] != -1):
                count += 1
                s[x] = -1
                s[y] = -1
                x -= 1
                y += 1
            i = y
        else:
            i += 1
    print(count)
    print('Yes' if count % 2 == 1 else 'No')


if __name__ == "__main__":
    main()
