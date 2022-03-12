#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <11/Jan/2019 05:50:24 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.codechef.com/JAN19A/problems/XYPIZQ
#

# ///==========Libraries, Constants and Functions=============///


import sys
# from atexit import register
# from io import StringIO as stream

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


def main():
    from math import gcd
    #from decimal import Decimal
    for tc in range(int(input())):
        n, t, x, y, z = get_ints()
        #x = 180 / ((2 * n) + 1)
        if t == 1:
            if y > x:
                if z > y:
                    p = (2 * n) - y
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)
                else:
                    p = x
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)

            else:
                if z > y:
                    p = x
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)
                else:
                    p = (2 * n) + 1 - z
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)
        elif t == 2:
            p = (2 * n) + 1 - (2 * y)
            q = (2 * n) + 1
            while gcd(p, q) != 1:
                g = gcd(p, q)
                p = p // g
                q = q // g
            print(p, q)

        elif t == 3:
            if x < y:
                if z > y:
                    p = (2 * n) + 1 - x
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)
                else:
                    p = x
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)
            else:
                if z > y:
                    p = x
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)
                else:
                    p = (2 * n) + 1 - x
                    q = (2 * n) + 1
                    while gcd(p, q) != 1:
                        g = gcd(p, q)
                        p = p // g
                        q = q // g
                    print(p, q)

        elif t == 4:
            p = (2 * n) + 1 - (2 * y)
            q = (2 * n) + 1
            while gcd(p, q) != 1:
                g = gcd(p, q)
                p = p // g
                q = q // g
            print(p, q)

        #print(0.569225588078908 * pi)
        # print(Decimal(1.7883).as_integer_ratio())
if __name__ == "__main__":
    # fast_io()
    main()
