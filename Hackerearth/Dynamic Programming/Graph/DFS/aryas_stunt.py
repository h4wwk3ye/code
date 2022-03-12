#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <04/Jan/2019 11:43:27 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/aryas-stunt-63b3da17/
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


def explore(graph, node, visited, mx):
    stack = []
    stack.append(node)
    visited[node] = True
    curr_mx = arr[node - 1]
    if curr_mx >= mx:
        mx = curr_mx
        id = node
    while len(stack) != 0:
        node = stack.pop()
        for neighbour in graph[node]:
            if visited[neighbour] == False:
                curr_mx = arr[neighbour - 1]
                if curr_mx > mx:
                    mx = curr_mx
                    id = neighbour
                if curr_mx == mx:
                    id = min(neighbour, id)
                visited[neighbour] = True
                stack.append(neighbour)
    return mx, id


def DFS(graph, n):
    mx = 0
    visited = [False] * (n + 1)
    id = []
    for i in range(1, n + 1):
        if visited[i] == False:
            x, y = explore(graph, i, visited, 0)
            mx += x
            id.append(y)
    return mx, id


if __name__ == "__main__":
        # fast_io()
    n, m = get_ints()
    arr = get_array()
    graph = {i + 1: [] for i in range(n)}
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    mx, id = DFS(graph, n)
    print(mx, sum(arr) - mx)
    id.sort()
    print(*id)
