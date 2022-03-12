#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Jan/2019 11:48:09 PM>


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


def check(i, j, n, m):
    if i >= 0 and i < n and j >= 0 and j < m:
        return True
    return False


def precompute(matrix, n, m):
    for i in range(n):
        for j in range(m):
            d = {}
            if check(i, j - 1, n, m) == True:
                if check(i, j - 2, n, m) == True:
                    d[matrix[i][j - 2]] = 1
                if check(i - 1, j - 1, n, m) == True:
                    d[matrix[i - 1][j - 1]] = 1
            if check(i - 1, j, n, m) == True:
                if check(i - 2, j, n, m) == True:
                    d[matrix[i - 2][j]] = 1
                if check(i - 1, j + 1, n, m) == True:
                    d[matrix[i - 1][j + 1]] = 1
            for p in range(1, 15):
                if p not in d:
                    matrix[i][j] = p
                    break


def fill(matrix, n, m):
    matrix[0][0] = 1
    matrix[1][0] = 1
    matrix[0][1] = 2
    matrix[1][1] = 3
    for j in range(2, m):
        for i in range(2):
            if i == 0:
                d = {}
                d[matrix[i][j - 2]] = 1
                d[matrix[i + 1][j - 1]] = 1
                for p in range(1, 4):
                    if p not in d:
                        matrix[i][j] = p
                        break
            if i == 1:
                d = {}
                d[matrix[i][j - 2]] = 1
                d[matrix[i - 1][j - 1]] = 1
                for p in range(1, 4):
                    if p not in d:
                        matrix[i][j] = p
                        break


if __name__ == "__main__":
        # fast_io()
    matrix = [[0] * 50 for _ in range(50)]
    precompute(matrix, 50, 50)
    for tc in range(int(input())):
        n, m = get_ints()
        if m == 2 and n == 2:
            print(2)
            print(1, 1)
            print(2, 2)
            continue
        elif m == 2 and n != 1:
            print(3)
            for i in range(max(n, m)):
                print(i % 3 + 1, i % 3 + 1)
            continue
        elif n == 2 and m == 1:
            print(1)
            print(1)
            print(1)
            continue
        elif n == 2 and m != 1:
            print(3)
            x = [[0] * m for _ in range(2)]
            fill(x, 2, m)
            for i in range(n):
                print(*x[i])
            continue

        mx = 0
        for i in range(n):
            for j in range(m):
                mx = max(matrix[i][j], mx)

        print(mx)
        for i in range(n):
            print(*matrix[i][:m])
