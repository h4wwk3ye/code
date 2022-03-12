#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Feb/2019 06:31:43 PM>


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


N = 105
graph = [[] for _ in range(N)]
component = [0] * N
visited = [False] * N


def explore(node):
    global cnt
    visited[node] = True
    component[node] = cnt
    for neighbour, color in graph[node]:
        if visited[neighbour] == False:
            explore(neighbour)


def dfs(n):
    global cnt
    cnt = 0
    for i in range(1, n + 1):
        if visited[i] == False:
            cnt += 1
            explore(i)


def explore_o(node, c):
    global ans, s
    visited[node] = True
    for neighbour, color in graph[node]:
        if visited[neighbour] == False and color == c:
            if neighbour == v:
                s.add(color)
            explore_o(neighbour, c)


def dfs_o(u):
    global visited, ans, flag, s
    ans = 0
    s = set()
    for neighbour, color in graph[u]:
        visited = [False] * N
        visited[u] = True
        flag = 0
        if neighbour == v:
            s.add(color)
            continue
        explore_o(neighbour, color)
    return len(s)


def main():
    global n, m
    n, m = get_ints()
    for _ in range(m):
        u, x, c = get_ints()
        graph[u].append((x, c))
        graph[x].append((u, c))
    dfs(n)
    global v
    for tc in range(int(input())):
        u, v = get_ints()
        if component[u] != component[v]:
            print(0)
            continue
        print(dfs_o(u))


if __name__ == "__main__":
    main()
