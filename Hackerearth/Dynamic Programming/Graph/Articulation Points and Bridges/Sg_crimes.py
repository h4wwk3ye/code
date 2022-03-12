#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <22/Jan/2019 02:50:29 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/sg-and-graphs/
#

# ///==========Libraries, Constants and Functions=============///


import sys
#sys.stdin = open('input.txt', 'r')
import resource
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))
sys.setrecursionlimit(10**6)
inf = float("inf")
mod = 1000000007

import threading


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

            low[node] = min(low[child], low[node])

            if low[child] > disc[node]:
                bridges[node, child] = 1
                bridges[child, node] = 1
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
    n, m, q = get_ints()
    graph = {i + 1: [] for i in range(n)}
    edges = {}
    for i in range(m):
        u, v, z = get_ints()
        graph[u].append(v)
        graph[v].append(u)
        edges[z] = u, v

    dfs(graph, n, m)

    for _ in range(q):
        x = int(input())
        edge = edges[x]
        if edge in bridges:
            print('YES')
        else:
            print('no')


if __name__ == "__main__":
    main()
