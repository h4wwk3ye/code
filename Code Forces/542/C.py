#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <24/Feb/2019 10:04:45 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(10**6)
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def dis(x1, y1, x2, y2):
    return (pow(x1-x2, 2)+pow(y1-y2, 2))


def check(i, j):
    if (i >= 0 and i < n and j >= 0 and j < n):
        return True
    return False


def neighbours(i, j):
    arr = [[i, j-1], [i, j+1], [i-1, j], [i+1, j]]
    return arr


def dfs(x, y):
    visited[x][y] = True
    for p in neighbours(x, y):
        u, v = p[0], p[1]
        if check(u, v) == True and visited[u][v] == False and matrix[u][v] == '0':
            if (cnt == 0):
                first.append((u, v))
            else:
                second.append((u, v))
            dfs(u, v)


def main():
    global n, r1, r2, c1, c2, matrix, visited, first, second, cnt
    cnt = 0
    first = []
    second = []
    n = int(input())
    r1, c1 = get_ints()
    r1 -= 1
    c1 -= 1
    r2, c2 = get_ints()
    r2 -= 1
    c2 -= 1
    matrix = [0 for _ in range(n)]
    for i in range(n):
        matrix[i] = input().strip()
    visited = [[False]*n for _ in range(n)]
    first.append((r1, c1))
    dfs(r1, c1)
    cnt += 1
    if visited[r2][c2] == True:
        print(0)
        return
    second.append((r2, c2))
    dfs(r2, c2)
    mn = inf
    # print(first)
    # print(second)
    for i in first:
        for j in second:
            mn = min(mn, dis(*i, *j))

    print(mn)


if __name__ == "__main__":
    main()
