#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Jan/2019 08:56:37 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream

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
    if i < 0 or i >= n or j < 0 or j >= m:
        return False
    return True


def bfs(i, j):
    global mx
    count = 1
    visited[i][j] = True
    from collections import deque
    queue = deque()
    queue.append((i, j))
    while queue:
        x, y = queue.pop()
        if check(x - 1, y - 1) and matrix[x - 1][y - 1] == 1 and visited[x - 1][y - 1] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x - 1, y - 1))
            visited[x - 1][y - 1] = True
        if check(x, y - 1) and matrix[x][y - 1] == 1 and visited[x][y - 1] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x, y - 1))
            visited[x][y - 1] = True
        if check(x + 1, y + 1) and matrix[x + 1][y + 1] == 1 and visited[x + 1][y + 1] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x + 1, y + 1))
            visited[x + 1][y + 1] = True
        if check(x - 1, y) and matrix[x - 1][y] == 1 and visited[x - 1][y] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x - 1, y))
            visited[x - 1][y] = True
        if check(x - 1, y + 1) and matrix[x - 1][y + 1] == 1 and visited[x - 1][y + 1] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x - 1, y + 1))
            visited[x - 1][y + 1] = True
        if check(x, y + 1) and matrix[x][y + 1] == 1 and visited[x][y + 1] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x, y + 1))
            visited[x][y + 1] = True
        if check(x + 1, y) and matrix[x + 1][y] == 1 and visited[x + 1][y] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x + 1, y))
            visited[x + 1][y] = True
        if check(x + 1, y - 1) and matrix[x + 1][y - 1] == 1 and visited[x + 1][y - 1] == False:
            count += 1
            mx = max(mx, count)
            queue.append((x + 1, y - 1))
            visited[x + 1][y - 1] = True


if __name__ == "__main__":
    # fast_io()
    for tc in range(int(input())):
        n, m = get_ints()
        visited = [[False] * m for _ in range(n)]
        counter = 0
        global mx
        mx = 0
        matrix = [0] * n
        for i in range(n):
            matrix[i] = get_array()
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 1 and visited[i][j] == False:
                    bfs(i, j)
                    counter += 1
        print(counter, mx)
