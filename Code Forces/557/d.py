#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <05/May/2019 10:36:47 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


# ///==========MAIN=============///


def main():
    n, m = get_ints()
    d = {}
    for i in range(m):
        a, b = get_ints()
        d[(a, b)] = 1
        d[(b, a)] = 1

    divisors = []

    p = 1
    while p * p <= n:
        if n % p == 0:
            divisors.append(p)
            divisors.append(n // p)
        p += 1

    for j in range(len(divisors)):
        i = divisors[j]
        flag = True
        for k in d:
            x, y = k[0], k[1]
            a = (x + i) % (n + 1)
            b = (y + i) % (n + 1)
            if a < x:
                a += 1
            if b < y:
                b += 1

            if (a, b) not in d:
                flag = False
                break

        if flag == True:
            print('YES')
            return

    print('NO')


if __name__ == "__main__":
    main()
