#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Jan/2019 08:40:08 PM>


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
    def __init__(self, vertices):
        self.adjacency = {i + 1: [] for i in range(vertices)}

    def add_edge(self, u, v, w):
        self.adjacency[u].append([w, v])


def prim(graph):
    from heapq import heappop, heappush, heapify
    heap = [(0, 1)]
    visited = [False] * 10005
    total = 0
    while len(heap) != 0:
        cost, node = heappop(heap)
        if visited[node] == True:
            continue
        visited[node] = True
        total += cost
        for weight, neighbour in graph.adjacency[node]:
            if visited[neighbour] == False:
                heappush(heap, (weight, neighbour))
    return total


def main():
    n, m = get_ints()
    graph = Graph(n)
    for i in range(m):
        u, v, w = get_ints()
        graph.add_edge(u, v, w)
        graph.add_edge(v, u, w)
    print(prim(graph))


if __name__ == "__main__":
        # fast_io()
    main()
