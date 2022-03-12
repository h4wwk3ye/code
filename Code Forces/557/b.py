#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <04/May/2019 11:12:46 PM>


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
    A = [0] * n
    B = [0] * n
    for i in range(n):
        A[i] = get_array()
    for i in range(n):
        B[i] = get_array()

    for i in range(n):
        for j in range(m):
            if A[i][j] < B[i][j]:
                A[i][j], B[i][j] = B[i][j], A[i][j]

    for i in range(n):
        for j in range(m):
            if i > 0 and A[i][j] <= A[i - 1][j]:
                print('Impossible')
                return
            if j > 0 and A[i][j] <= A[i][j - 1]:
                print('Impossible')
                return

    for i in range(n):
        for j in range(m):
            if i > 0 and B[i][j] <= B[i - 1][j]:
                print('Impossible')
                return
            if j > 0 and B[i][j] <= B[i][j - 1]:
                print('Impossible')
                return

    print('Possible')


if __name__ == "__main__":
    main()
