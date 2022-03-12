#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <08/Feb/2019 03:25:45 PM>


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
n, m = 0, 0
x, y = 0, 0
u, v = 0, 0
matrix = [[0] * 205 for _ in range(205)]
distance_1 = [[0] * 205 for _ in range(205)]
distance_2 = [[0] * 205 for _ in range(205)]
visited_1 = [[0] * 205 for _ in range(205)]
visited_2 = [[0] * 205 for _ in range(205)]

from collections import deque


def neighbours(x, y):
    #print(type(x), type(y))
    arr = [(x, y - 1), (x - 1, y), (x + 1, y), (x, y + 1)]
    return arr


def check(i, j):
    global n, m
    if ((i >= 1 and i <= n) and (j >= 1 and j <= m)):
        return True
    return False


def bfs_1(x, y):
    global n, m
    queue = deque()
    queue.append((x, y))
    visited_1[x][y] = 1
    while len(queue) != 0:
        p = queue.popleft()
        a, b = p[0], p[1]
        #visited_1[a][b] = 1
        neigh = neighbours(a, b)
        for c in neigh:
            # print(c)
            h, g = c[0], c[1]
            if visited_1[h][g] == 0 and check(h, g) == True and matrix[h][g] == 0:
                distance_1[h][g] = 1 + distance_1[a][b]
                queue.append((h, g))
                visited_1[h][g] = 1


def bfs_2(x, y):
    global n, m
    queue = deque()
    queue.append((x, y))
    visited_2[x][y] = 1
    while len(queue) != 0:
        p = queue.popleft()
        a, b = p[0], p[1]
        #visited_2[a][b] = 1
        neigh = neighbours(a, b)
        for c in neigh:
            # print(c)
            h, g = c[0], c[1]
            if visited_2[h][g] == 0 and check(h, g) == True and matrix[h][g] == 0:
                distance_2[h][g] = 1 + distance_2[a][b]
                queue.append((h, g))
                visited_2[h][g] = 1


def main():
    global n, m
    n, m = get_ints()
    x, y = get_ints()
    matrix[x][y] = 1
    u, v = get_ints()
    matrix[u][v] = 2

    bfs_1(x, y)
    bfs_2(u, v)
    count = 0
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if distance_1[i][j] == distance_2[i][j] and distance_1[i][j] != 0 and distance_2[i][j] != 0:
                count += 1
    '''for i in range(1, n + 1):
        print(distance_1[i][1:m + 1])
    #print('yes')
    for i in range(1, n + 1):
        print(distance_2[i][1: m + 1])'''
    print(count)


if __name__ == "__main__":
    main()
