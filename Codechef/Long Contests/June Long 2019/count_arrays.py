#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <16/Jun/2019 06:37:02 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior
from __future__ import division, print_function
from io import IOBase, BytesIO
import os
import sys
py2 = round(0.5)
if py2:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

mod = 10**9 + 7


def s1(n, m, k):
    ans = 0
    for i in range(max(m, n)):
        ans += pow(i, max(m, n), mod) - pow(i, min(m, n), mod)
    return ans % mod


def s2(n, m, k):
    ans = 0
    for i in range(k):
        curr = (((pow(i + 1, n, mod) - (pow(i, n, mod))))
                * ((pow(i + 1, m, mod) - (pow(i, m, mod))))) % mod
        ans += curr % mod
        print(curr)
    return(ans % mod)


def main():
    sys.stdin = open("inp.txt", "r")
    cnt = 0
    for tc in range(int(input())):
        n, m, k = get_ints()
        print(s2(n, m, k))
        '''if s1(n, m, k) != s2(n, m, k):
            print(n, m, k)
            print(s1(n, m, k), s2(n, m, k))
            cnt += 1
            print(cnt)'''


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
