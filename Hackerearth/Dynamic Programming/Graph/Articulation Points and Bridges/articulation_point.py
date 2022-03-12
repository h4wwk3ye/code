#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <17/Jan/2019 07:45:01 PM>


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


ans = []
bridges = []


def explore(graph, node, visited, low, disc, parent, time):
    visited[node] = True
    low[node] = disc[node] = time   # previsited value
    children = 0
    for child in graph[node]:
        if visited[child] == False:
            parent[child] = node
            children += 1
            explore(graph, child, visited, low, disc, parent, time + 1)
            low[node] = min(low[node], low[child])
            if parent[node] == -1 and children > 1:  # if node is the root of dfs tree
                ans.append(node)
            elif parent[node] != -1 and low[child] >= disc[node]:  # no back edge from subtree
                ans.append(node)
            if low[child] > disc[node]:  # edge is a bridge
                if node > child:
                    bridges.append([child, node])
                else:
                    bridges.append([node, child])
        elif child != parent[node]:
            low[node] = min(low[node], disc[child])


def dfs(graph, n, m):
    visited = [False] * n
    low = [inf] * n
    disc = [inf] * n
    parent = [-1] * n
    for i in range(n):
        if visited[i] == False:
            explore(graph, i, visited, low, disc, parent, 0)


def main():
    n, m = get_ints()
    graph = {i: [] for i in range(n)}
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)

    # Articulation Point
    dfs(graph, n, m)
    print(len(ans))
    print(*sorted(ans))
    bridge = sorted(bridges)
    print(len(bridge))
    for i in range(len(bridge)):
        print(bridge[i][0], bridge[i][1])


if __name__ == "__main__":
    main()
