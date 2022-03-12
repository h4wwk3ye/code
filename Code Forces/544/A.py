#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Mar/2019 08:57:39 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    x = input().strip()
    y = input().strip()
    h1, m1 = int(x[:2]), int(x[3:])
    h2, m2 = int(y[:2]), int(y[3:])
    x1 = h1*60+m1
    x2 = h2*60+m2
    u = (x1+x2)//2
    h = u // 60
    m = u-(h*60)
    if h < 10:
        h = '0'+str(h)
    if m < 10:
        m = '0'+str(m)
    print(h, ':', m, sep='')


if __name__ == "__main__":
    main()
