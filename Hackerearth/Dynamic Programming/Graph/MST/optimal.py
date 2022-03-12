#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <08/Jan/2019 09:49:13 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/optimal-connectivity-c6ae79ca/
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


def find(x, parent):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]


def union(x, y, rank):
    x_id = find(x)
    y_id = find(y)
    if x_id == y_id:
        return
    if x_id > y_id:
        parent[y_id] = x_id
    else:
        parent[x_id] = y_id
        if rank[x_id] == rank[y_id]:
            rank[y_id] += 1


def main():
    n = int(input())
    graph = {i + 1: [] for i in range(n)}
    for i in range(n - 1):
        u, v, w = get_ints()
        graph[u].append((w, v))
        graph[v].append((w, u))
    parent = [i for i in range(n + 1)]
    rank = [0] * (n + 1)
    cost = kruskal(graph)


if __name__ == "__main__":
        # fast_io()
    main()
