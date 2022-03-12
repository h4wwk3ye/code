#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <17/Jan/2019 08:11:30 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


points = [False] * (101)


def explore(graph, node, visited, parent, low, disc, time):
    visited[node] = True
    low[node] = disc[node] = time
    children = 0
    for child in graph[node]:
        if visited[child] == False:
            children += 1
            parent[child] = node
            explore(graph, child, visited, parent, low, disc, time + 1)
            low[node] = min(low[node], low[child])

            if parent[node] == -1 and children > 1:
                points[node] = True

            elif parent[node] != -1 and low[child] >= disc[node]:
                points[node] = True

        elif parent[child] != node:
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
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)

    dfs(graph, n, m)
    for tc in range(int(input())):
        x = int(input())
        if points[x] == False:
            print('Not Satisfied')
        else:
            print('Satisfied', len(graph[x]))


if __name__ == "__main__":
    main()
