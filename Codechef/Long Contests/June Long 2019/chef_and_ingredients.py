#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <09/Jun/2019 01:25:43 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


mod = 10**9 + 7


def main():
    for tc in range(int(input())):
        n, k = get_ints()
        a = k - 1
        d = n - 1
        t = a // d
        l = a - (d * t)
        t += 1
        ans = int(t * (a + l))
        ans //= 2
        print(ans % mod)


if __name__ == "__main__":
    main()
