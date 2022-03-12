#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <08/Jan/2019 11:06:32 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/b-31/
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


def prims(graph):
    from heapq import heappop, heappush
    heap = [(0, 1)]
    visited = [False] * 100005
    total = 0
    while len(heap) != 0:
        cost, node = heappop(heap)
        if visited[node] == True:
            continue
        visited[node] = True
        total += cost
        for weight, neighbour in graph[node]:
            if visited[neighbour] == False:
                heappush(heap, (weight, neighbour))
    return total


def main():
    n = int(input())
    time = [0] * n
    for i in range(n):
        time[i] = int(input())
    graph = {i + 1: [] for i in range(n)}
    for i in range(n - 1):
        a, b, w = get_ints()
        graph[a].append((w, b))
        graph[b].append((w, a))
    prims(graph)


if __name__ == "__main__":
        # fast_io()
    main()
