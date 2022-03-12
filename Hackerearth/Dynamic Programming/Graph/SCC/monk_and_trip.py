#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <25/Jan/2019 12:42:06 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/monk-and-his-unique-trip/
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
stack = []
visited = [False] * (100005)
visited_other = [False] * (100005)
global scc
scc = 0
component = [-1] * 100005
visited_third = [False] * 100005
edges = []
new_g = {i: [] for i in range(1, 100005)}
sec_stack = []


def explore(node):
    visited[node] = True
    for neighbour in graph_r[node]:
        if visited[neighbour] == False:
            explore(neighbour)
    stack.append(node)


def dfs(n):
    for i in range(1, n + 1):
        if visited[i] == False:
            explore(i)


def explore_o(node):
    visited_other[node] = True
    component[node] = scc
    for neighbour in graph[node]:
        if visited_other[neighbour] == False:
            explore_o(neighbour)


def dfs_o():
    global scc
    for node in reversed(stack):
        if visited_other[node] == False:
            scc += 1
            explore_o(node)


def explore_third(node):
    visited_third[node] = True
    for neighbour in new_g[node]:
        if visited_third[neighbour] == False:
            explore_third(neighbour)
    sec_stack.append(node)


def dfs_third(scc):
    for i in range(1, scc + 1):
        if visited_third[i] == False:
            explore_third(i)


def main():
    n, m = get_ints()
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph_r[v].append(u)
        edges.append((u, v))

    dfs(n)
    dfs_o()

    for i in range(m):
        if component[edges[i][0]] != component[edges[i][1]]:
            new_g[component[edges[i][0]]].append(component[edges[i][1]])

    dfs_third(scc)

    dist = [0] * (scc + 1)

    while len(sec_stack) != 0:
        node = sec_stack.pop()
        for neighbour in new_g[node]:
            dist[neighbour] = max(dist[neighbour], 1 + dist[node])
    print(max(dist))


if __name__ == "__main__":
    main()
