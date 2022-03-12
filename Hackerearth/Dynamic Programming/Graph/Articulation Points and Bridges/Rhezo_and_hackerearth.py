#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <17/Jan/2019 08:36:22 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-hackerearth-3/
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


bridges = {}


def explore(graph, node, visited, parent, low, disc, time):
    visited[node] = True
    low[node] = disc[node] = time

    for child in graph[node]:
        if visited[child] == False:
            parent[child] = node
            explore(graph, child, visited, parent, low, disc, time + 1)

            low[node] = min(low[node], low[child])

            if low[child] > disc[node]:
                bridges[child, node] = 1
                bridges[node, child] = 1

        elif child != parent[node]:
            low[node] = min(low[node], disc[child])


def dfs(graph, n, m):
    visited = [False] * (n + 1)
    parent = [-1] * (n + 1)
    low = [inf] * (n + 1)
    disc = [inf] * (n + 1)
    for i in range(1, n + 1):
        if visited[i] == False:
            explore(graph, i, visited, parent, low, disc, 0)


def main():
    n, m = get_ints()
    graph = {i + 1: [] for i in range(n)}
    edges = {}
    for i in range(m):
        u, v = get_ints()
        edges[i + 1] = u, v
        graph[u].append(v)
        graph[v].append(u)

    dfs(graph, n, m)

    for tc in range(int(input())):
        x = int(input())
        edge = edges[x]
        if edge in bridges:
            print('Unhappy')
        else:
            print('Happy')


if __name__ == "__main__":
    main()
