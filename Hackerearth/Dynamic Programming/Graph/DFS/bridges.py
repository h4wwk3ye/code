#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <04/Jan/2019 10:25:48 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#   https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/rhezo-and-critical-links-3/
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream

sys.setrecursionlimit(200000)

inf = float("inf")
mod = 1000000007
sys.stdin = open('input.txt', 'r')


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def explore_other(graph, root, node, count, visited):
    visited[root] = True
    for vertex in graph[root]:
        if vertex != node and visited[vertex] == False:
            count += 1
            explore_other(graph, vertex, node, count, visited)


def check(graph, neighbour, node):
    neigh_count = 0
    node_count = 0
    visited = [False] * (n + 1)
    explore_other(graph, neighbour, node, neigh_count, visited)
    visited = [False] * (n + 1)
    explore_other(graph, node, neighbour, node_count, visited)
    return True if abs(neigh_count - node_count) < p else False


def explore(node, graph, visited, low, disc, parent, time):
    visited[node] = True
    disc[node] = time
    low[node] = time
    time += 1
    for neighbour in graph[node]:
        if visited[neighbour] == False:
            parent[neighbour] = node
            explore(neighbour, graph, visited, low, disc, parent, time)

            low[node] = min(low[node], low[neighbour])

            if low[neighbour] > disc[node]:
                # if check(graph, neighbour, node) == True:
                global Critical
                Critical += 1
        elif neighbour != parent[node]:
            low[node] = min(low[node], low[neighbour])


def DFS(graph, n):
    visited = [False] * (n + 1)
    time = 0
    low = [0] * (n + 1)
    disc = [0] * (n + 1)
    parent = [-1] * (n + 1)
    for i in range(1, n + 1):
        if visited[i] == False:
            explore(i, graph, visited, low, disc, parent, time)


if __name__ == "__main__":
    # fast_io()
    global Critical
    Critical = 0
    n, m, p = get_ints()
    graph = {i + 1: [] for i in range(n)}
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    DFS(graph, n)
    print(Critical)
