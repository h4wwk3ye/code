#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <05/Jan/2019 11:21:20 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
#from atexit import register
#from io import StringIO as stream

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


def right(n):
    #n = int(input())
    if n == 1:
        print(2)
        return
    ans = inf
    from math import ceil
    for i in range(1, n + 1):
        x = ceil(n / i) + i
        ans = min(ans, x)
    return ans


def main():
    n = int(input())
    if n == 1:
        print(2)
        return
    from math import sqrt, ceil, floor
    p = int(sqrt(n))
    i = p
    ans = p
    ans += 1
    while i < n:
        ans += 1
        i += p

    print(ans)


if __name__ == "__main__":
        # fast_io()
    main()
    '''import random
    while True:
        x = random.randint(1, 1000)
        a = main(x)
        b = right(x)
        if a != b:
            print(x, a, b)
            break
            '''
