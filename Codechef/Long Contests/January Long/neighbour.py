#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Jan/2019 12:51:48 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.codechef.com/JAN19A/problems/EARTSEQ
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


def check(i, j):
    if i >= 0 and i < 51 and j >= 0 and j < 51:
        return True
    return False


def precompute(matrix):
    for i in range(51):
        for j in range(51):
            d = {}
            if check(i, j - 1) == True:
                if check(i, j - 2) == True:
                    d[matrix[i][j - 2]] = 1
                if check(i - 1, j - 1) == True:
                    d[matrix[i - 1][j - 1]] = 1
            if check(i - 1, j) == True:
                if check(i - 2, j) == True:
                    d[matrix[i - 2][j]] = 1
                if check(i - 1, j + 1) == True:
                    d[matrix[i - 1][j + 1]] = 1
            for p in range(1, 15):
                if p not in d:
                    matrix[i][j] = p
                    break


def main():
    matrix = [[0] * 51 for i in range(51)]
    precompute(matrix)
    transpose = [list(i) for i in zip(*matrix)]
    for tc in range(int(input())):
        n, m = get_ints()
        if n == 1 and m == 1:
            print(1)
            print(1)
        elif n == 1 and m == 2:
            print(1)
            print(1, 1)
        elif n == 1:
            print(2)
            print(*matrix[0][:m])
        elif m == 1:
            if n == 2:
                print(1)
                print(1)
                print(1)
            else:
                print(2)
                for i in range(n):
                    print(transpose[i][0])
        elif m == 2 and n == 2:
            print(2)
            print(1, 1)
            print(2, 2)
        elif m == 2:
            print(3)
            for i in range(max(n, m)):
                print(i % 3 + 1, i % 3 + 1)
        elif n == 2 and m == 3:
            print(3)
            print(1, 1, 2)
            print(2, 3, 3)
        elif m <= 26 or n <= 26:
            print(4)
            if m <= 26:
                for i in range(n):
                    print(*matrix[i][:m])
            else:
                for i in range(n):
                    print(*transpose[i][:m])
        elif m == 27:
            print(4)
            x = matrix.copy()
            x[25][26] = 3
            for i in range(n):
                print(*x[i][:m])

        else:
            print(5)
            for i in range(n):
                print(*matrix[i][:m])


if __name__ == "__main__":
    # fast_io()
    main()
