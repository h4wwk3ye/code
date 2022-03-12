#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <05/Jan/2019 11:18:36 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream

inf = float("inf")
mod = 1000000007


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def check(seq):
    count = 0
    for i in seq:
        if i == '(':
            count += 1
        else:
            count -= 1
    return count


def main():
    n = int(input())
    count = 0
    brackets = [0] * n
    for i in range(n):
        brackets[i] = input().strip()
    for i in range(n):
        x = check(brackets[i])
        if x == 0:
            if brackets[i][0] == '(':
                brackets[i] = 0
            else:
                brackets[i] = inf
        else:
            brackets[i] = x
    from collections import Counter
    p = Counter(brackets)
    print(p)
    for i in p:
        if i == 0:
            count += (p[i] // 2)
            print(i, count)
        elif i == inf:
            count += (p[i] // 2)
            print(i, count)
        else:
            if -1 * i in p:
                count += min(p[i], p[-1 * i])
                print(i, count)
                p[i] = 0
                p[-1 * i] = 0

    print(count)


if __name__ == "__main__":
        # fast_io()
    main()
