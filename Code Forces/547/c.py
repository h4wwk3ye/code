#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Mar/2019 10:21:53 PM>


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
    n = int(input())
    q = get_array()

    p = [0]
    for i in q:
        p.append(p[-1]+i)

    mn = min(p)

    for i in range(n):
        p[i] = (p[i]-mn+1)

    d = {}
    for i in p:
        if i in d or i > n:
            print(-1)
            return
        d[i] = 1
    print(*p)


if __name__ == "__main__":
    main()
