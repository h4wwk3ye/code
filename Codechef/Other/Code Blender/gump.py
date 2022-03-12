#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Feb/2019 11:29:19 PM>


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
    from math import ceil, floor
    for tc in range(int(input())):
        k, n = get_ints()
        if n % k == 0:
            print(pow(n // k, k, mod))
            continue
        x = floor(n / k)
        a = (k * (ceil(n / k))) - n
        print((pow(x, a, mod) * pow(x + 1, k - a, mod)) % mod)


if __name__ == "__main__":
    main()
