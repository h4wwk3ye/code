#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Feb/2019 10:53:43 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(10**6)
import resource
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


visited = [[False for i in range(1000)] for j in range(1000)]
matrix = [0] * 1000
mx = 1
maxi = inf


def neighbours(i, j):
    arr = [(i, j - 1), (i - 1, j),
           (i + 1, j),  (i, j + 1)]
    return arr


def check(i, j, n, m):
    if i >= 0 and i < n and j >= 0 and j < m:
        return True
    return False


def dfs(i, j, n, m):
    global count, mx, maxi
    visited[i][j] = True
    for neighbour in neighbours(i, j):
        x, y = neighbour
        if check(x, y, n, m) == True and visited[x][y] == False:
            if matrix[x][y] == matrix[i][j]:
                # print(neighbour)
                count += 1
                if count > mx:
                    maxi = matrix[i][j]
                    mx = count
                elif count == mx and matrix[i][j] < maxi:
                    maxi = matrix[i][j]
                dfs(x, y, n, m)
    if count == mx and matrix[i][j] < maxi:
        maxi = matrix[i][j]


def main():
    n, m = get_ints()
    for i in range(n):
        matrix[i] = get_array()
    for i in range(n):
        for j in range(m):
            if visited[i][j] == False:
                global count
                count = 1
                dfs(i, j, n, m)
    print(maxi, mx)


if __name__ == "__main__":
    main()
