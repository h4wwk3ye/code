#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <11/Feb/2019 07:40:20 PM>


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


N = int(1e5 + 5)
problems = [[]for _ in range(N)]
n, k = 0, 0


def solve():
    x = 1


def main():
    global n, k
    n, k = get_ints()
    for i in range(n):
        problems[i] = get_array()
    solve()
    print(problems[:n])


if __name__ == "__main__":
    main()
