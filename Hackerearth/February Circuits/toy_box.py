#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Feb/2019 07:18:19 PM>


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
    n, m = get_ints()
    d = {i: [] for i in range(1, m + 1)}
    for _ in range(n):
        p, b = get_ints()
        d[b].append(p)
    ans = 0
    for i in d:
        if len(d[i]) != 0:
            ans += max(d[i])
    print(ans)


if __name__ == "__main__":
    main()
