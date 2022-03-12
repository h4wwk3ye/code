#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <16/May/2019 09:49:45 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


def main():
    arr = [0] * 7
    from math import sqrt

    matrix = [[0] * 8 for _ in range(8)]

    lst = [0, 4, 8, 15, 16, 23, 42]

    for i in range(2, 8):
        matrix[i][1] = lst[i - 1]
        matrix[1][i] = lst[i - 1]

    for i in range(2, 8):
        for j in range(2, 8):
            matrix[i][j] = matrix[i][1] * matrix[1][j]

    d = {}
    print('?', 1, 1, flush=True)
    x = int(input())
    x = int(sqrt(x))
    arr[1] = x

    print('?', 2, 2, flush=True)
    x = int(input())
    x = int(sqrt(x))
    arr[2] = x

    print('?', 3, 4, flush=True)
    x = int(input())

    for i in range(2, 8):
        for j in range(2, 8):
            if matrix[i][j] == x and i != j:
                a = i
                b = j
                break

    print('?', 4, 5, flush=True)
    y = int(input())

    for i in range(2, 8):
        for j in range(2, 8):
            if matrix[i][j] == y and i != j:
                c = i
                d = j
                break

    a = matrix[a][1]
    b = matrix[1][b]
    c = matrix[c][1]
    d = matrix[1][d]

    if (a == b or a == c or a == d):
        arr[4] = a
        arr[3] = x // a
        arr[5] = y // a

    elif (b == a or b == c or b == d):
        arr[4] = b
        arr[3] = x // b
        arr[5] = y // b

    elif (c == b or a == c or c == d):
        arr[4] = c
        arr[3] = x // c
        arr[5] = y // c

    elif (d == b or d == c or a == d):
        arr[4] = d
        arr[3] = x // d
        arr[5] = y // d

    # print(arr)

    if 4 not in arr:
        arr[6] = 4
    elif 8 not in arr:
        arr[6] = 8
    elif 15 not in arr:
        arr[6] = 15
    elif 16 not in arr:
        arr[6] = 16
    elif 23 not in arr:
        arr[6] = 23
    elif 42 not in arr:
        arr[6] = 42

    print('!', *arr[1:7], flush=True)


if __name__ == "__main__":
    main()
