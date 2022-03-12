#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <14/Feb/2019 11:25:46 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
import threading
sys.setrecursionlimit(10**6)


inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


N = 150005
graph = [[] for _ in range(N)]
visited = [False] * N
vertices, edges = 0, 0
flag = 1


def explore(node):
    global visited, flag, vertices, edges
    visited[node] = True
    vertices += 1
    edges += len(graph[node])

    for neighbour in graph[node]:
        if visited[neighbour] == False:
            explore(neighbour)


def dfs(n):
    global visited, flag, vertices, edges
    for i in range(1, n + 1):
        if visited[i] == False:
            vertices, edges = 0, 0
            explore(i)
            if edges != vertices * (vertices - 1):
                flag = 0
                return


def main():
    n, m = get_ints()
    for _ in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    dfs(n)
    print("YES" if flag == 1 else "NO")


if __name__ == "__main__":
    threading.stack_size(10**8)
    t = threading.Thread(target=main)
    t.start()
    t.join()
