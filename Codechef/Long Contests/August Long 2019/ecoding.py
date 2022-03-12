#    !/usr/bin/env python3
#    encoding: UTF-8
#    Modified: <12/Aug/2019 01:00:11 PM>


#    ✪ H4WK3yE乡
#    Mohd. Farhan Tahir
#    Indian Institute Of Information Technology (IIIT), Gwalior


import sys
import os
from io import IOBase, BytesIO


def main():
    mod = 10**9+7
    a = [0]*(10**6)
    b = [0]*(10**6)
    c = [0]*(10**6+5)

    for i in range(1, 10**6):
        x = str(i)
        n = len(x)-1
        prev = -1
        for j in x:
            if j != prev:
                a[i] += (int(j)*pow(10, n, mod)) % mod
            n -= 1
            prev = j
        a[i] %= mod
        a[i] += a[i-1]
        a[i] %= mod

    for i in range(0, 10**6):
        x = str(i + 10**6)
        n = len(x)-1
        prev = -1
        for j in x:
            if j != prev:
                b[i] += (int(j)*pow(10, n, mod)) % mod
            n -= 1
            prev = j
        b[i] %= mod
        if i == 0:
            b[i] += a[-1]
        else:
            b[i] += b[i-1]
        b[i] %= mod

    for i in range(0, 10**6+5):
        x = str(i + 10**12)
        n = len(x)-1
        prev = -1
        for j in x:
            if j != prev:
                c[i] += (int(j)*pow(10, n, mod)) % mod
            n -= 1
            prev = j
        c[i] %= mod
        if i == 0:
            c[i] += b[-1]
        else:
            c[i] += c[i-1]
        c[i] %= mod

    #print(a[:12], b[:10], c[:10])
    for tc in range(int(input())):
        nl, l = get_ints()
        nr, r = get_ints()
        x, y = 0, 0
        if l < 10**6:
            i = l-1
            x = a[i]
        elif l < 10**12:
            i = (l-1) % 10**6
            x = b[i]
        else:
            i = (l-1) % (10**6)

            x = c[i]

        if r < 10**6:
            i = r
            y = a[i]
        elif r < 10**12:
            i = r % 10**6
            y = b[i]
        else:
            i = r % (10**6)
            if i == 0:
                if r == 10**18:
                    y = c[-1]
                else:
                    y = c[i]
            else:
                y = c[i]

        print((y-x) % mod)


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
