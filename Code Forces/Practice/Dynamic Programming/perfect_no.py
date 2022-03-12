#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

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


def sum_digits(n):
    x = 0
    while n > 0:
        x += (n % 10)
        n //= 10
    return x


def main():
    # arr=[10]*10005
    n = int(input())
    ans = 10
    while n > 0:
        ans += 9
        if sum_digits(ans) == 10:
            n -= 1
    print(ans)


if __name__ == "__main__":
    main()
