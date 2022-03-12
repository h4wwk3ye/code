#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <04/Jan/2019 07:48:22 PM>


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
sys.setrecursionlimit(200000)
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


def BFS(graph, x, n, arr):
    visited = [False] * (n + 2)
    visited[1] = True
    from collections import deque
    queue = deque()
    queue.append(1)
    while queue:
        node = queue.popleft()
        if (node == 1 and len(graph[node]) != 2) or (node != 1 and len(graph[node])) != 3:
            graph[node].append(n + 1)
            arr.append(x)
            return
        for neighbour in graph[node]:
            if visited[neighbour] == False:
                queue.append(neighbour)


def explore(graph, visited, node, arr):
    visited[node] = True
    for neighbour in graph[node]:
        if visited[neighbour] == False:
            arr[node - 1] += arr[neighbour - 1]
            print(node, neighbour)
            explore(graph, visited, neighbour, arr)


def DFS(graph, n, arr):
    visited = [False] * (n + 2)
    explore(graph, visited, 1, arr)


def main():
    n, x = get_ints()
    arr = get_array()
    graph = {i + 1: [] for i in range(n + 1)}
    for i in range(n - 1):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    # print(graph)
    BFS(graph, x, n, arr)
    #print(graph, arr)
    DFS(graph, n, arr)
    # print(arr)
    print(sum(arr))


if __name__ == "__main__":
        # fast_io()
    main()
