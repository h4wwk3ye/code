#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Jan/2019 07:25:54 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
#from atexit import register
#from io import StringIO as stream

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


class Graph:
    def __init__(self, edge):
        self.edges = []

    def add_edge(self, a, b, w):
        self.edges.append([w, [a, b]])


def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


def union(x, y):
    x_id = find(x)
    y_id = find(y)
    if x_id == y_id:
        return
    if rank[x_id] > rank[y_id]:
        parent[y_id] = x_id
    else:
        parent[x_id] = y_id
        if rank[x_id] == rank[y_id]:
            rank[y_id] += 1


def kruskal(graph):
    for edge in graph.edges:
        if find(edge[1][0]) != find(edge[1][1]):
            global cost
            cost += edge[0]
            union(edge[1][0], edge[1][1])


def main():
    n, m = get_ints()
    graph = Graph(m)
    for i in range(m):
        a, b, w = get_ints()
        graph.add_edge(a, b, w)
    graph.edges.sort()
    kruskal(graph)
    print(cost)


if __name__ == "__main__":
        # fast_io()
    parent = [i for i in range(10005)]
    rank = [0 for _ in range(10005)]
    cost = 0
    main()
