#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <08/Feb/2019 03:59:37 PM>


#	H4WK3yE
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
N = 10**5 + 5
arr = [0] * N


N = 10**5 + 5
arr = [0] * N


def precompute():
    arr[1] = 1
    pre = 1
    for i in range(2, N):
        arr[i] = ((i % mod) * pow(pre, mod - 2, mod)) % mod
        pre *= i
        pre %= mod


def main():
    precompute()
    # print(arr[1:100])
    for tc in range(int(input())):
        print(arr[int(input())] % mod)


if __name__ == "__main__":
    main()
