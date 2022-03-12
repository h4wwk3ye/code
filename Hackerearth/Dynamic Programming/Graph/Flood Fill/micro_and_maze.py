#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <16/Jan/2019 07:04:57 PM>


#	✪ H4WK3yE乡
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


def check(x, y, n, m, matrix):
    if x < 0 or y < 0 or x >= n or y >= m or matrix[x][y] == 0:
        return False
    return True


def dfs(x, y, matrix, n, m, visited):
    if x == n - 1 and y == m - 1:
        return True
    if check(x, y, n, m, matrix) == False:
        return
    if visited[x][y] == True:
        return
    visited[x][y] = True
    return dfs(x - 1, y, matrix, n, m, visited) or dfs(x + 1, y, matrix, n, m, visited) or dfs(x, y - 1, matrix, n, m, visited) or dfs(x, y + 1, matrix, n, m, visited)


def main():
    n, m = get_ints()
    matrix = [0] * n
    for i in range(n):
        matrix[i] = get_array()
    visited = [[False] * m for i in range(n)]
    print('Yes' if dfs(0, 0, matrix, n, m, visited) == True else 'No')


if __name__ == "__main__":
    main()
