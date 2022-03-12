#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Jan/2019 08:02:35 PM>


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


vertices = []


def explore(graph, node, visited, parent, low, disc, time):
    visited[node] = True
    low[node] = disc[node] = time
    children = 0
    for child in graph[node]:
        if visited[child] == False:
            parent[child] = node
            children += 1
            explore(graph, child, visited, parent, low, disc, time + 1)

            low[node] = min(low[node], low[child])

            if parent[node] == -1 and children > 1:
                vertices.append(node)
            elif parent[node] != -1 and low[child] >= disc[node]:
                vertices.append(node)
        elif parent[node] != child:
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
    weight = get_array()
    for i in range(m):
        x, y = get_ints()
        graph[x].append(x)
        graph[y].append(x)

    dfs(graph, n, m)

    if len(vertices) == 0:
        print(-1)


if __name__ == "__main__":
    main()
