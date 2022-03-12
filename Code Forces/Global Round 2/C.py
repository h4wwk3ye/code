#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <06/Apr/2019 06:37:45 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    global n, m
    n, m = get_ints()
    global A, B
    A = [[0]*m for _ in range(n)]
    B = [[0]*m for _ in range(n)]
    for i in range(n):
        A[i] = get_array()
    for i in range(n):
        B[i] = get_array()

    C = [[0]*m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if A[i][j] == B[i][j]:
                C[i][j] == 0
            else:
                C[i][j] = 1

    for i in range(n):
        for j in range(m):
            if C[i][j] == 1:
                t1 = i+1
                t2 = j+1
                while t1 < n and C[t1][j] == 0:
                    t1 += 1
                while t2 < m and C[i][t2] == 0:
                    t2 += 1
                if t1 == n or t2 == m:
                    print('NO')
                    return
                C[i][t2] = 0
                C[t1][j] = 0
                C[t1][t2] = 1-C[t1][t2]

    print('YES')


if __name__ == "__main__":
    main()
