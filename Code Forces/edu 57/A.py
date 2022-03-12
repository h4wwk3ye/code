#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#   https://codeforces.com/contest/1096/problem/0
#

# ///==========Libraries, Constants and Functions=============///


import sys
from io import StringIO as stream
from atexit import register
inf = float("inf")
mod = 1000000007


def sync_with_stdio():
    global input
    sys.stdin = stream(sys.stdin.read())

    def input(): return sys.stdin.readline()
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        l, r = get_ints()
        print(l, 2 * l)


if __name__ == "__main__":
    # sync_with_stdio()
    main()
