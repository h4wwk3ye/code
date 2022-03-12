#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Feb/2019 04:02:16 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
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


graph = {i: [] for i in range(1, 100005)}
graph_r = {i: [] for i in range(1, 100005)}
visited = [False] * 100005
stack = []
visited_other = [False] * 100005
scc = [0] * 100005


def explore(node):
    visited[node] = True
    for neighbour in graph_r[node]:
        if visited[neighbour] == False:
            explore(neighbour)
    stack.append(node)


def dfs(n):
    for node in range(1, n + 1):
        if visited[node] == False:
            explore(node)


def explore_other(node):
    visited_other[node] = True
    for neighbour in graph[node]:
        if visited_other[neighbour] == False:
            scc[node] = scc[neighbour] = 1
            explore_other(neighbour)


def dfs_o():
    for node in reversed(stack):
        if visited_other[node] == False:
            explore_other(node)


def main():
    n, m = get_ints()
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph_r[v].append(u)

    dfs(n)
    dfs_o()

    print(*scc[1:n + 1])


if __name__ == "__main__":
    main()
