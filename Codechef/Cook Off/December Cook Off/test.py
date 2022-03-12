#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

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
    l = len(s)
    n = int(s) % mod
    x = 0
    q = pow(10, l-1, mod)
    for i in range(l):
        x = (x*(q*10) % mod) % mod
        x = (x+n) % mod
        n = ((n-(int(s[i])*q)+mod) % mod)*10+int(s[i]) % mod
    print(x % mod)


if __name__ == "__main__":
    main()
