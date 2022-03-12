#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <13/Feb/2019 12:17:16 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://codeforces.com/gym/100571/problem/D
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


N = int(1e5 + 5)
graph = [[] for _ in range(N)]
distance = {i: {} for i in range(N)}
global n, m, C


def dijkstra(s):
    global graph, N, distance, n, m, C

    for i in range(1, C + 1):
        distance[s][i] = 0
    distance[s][-1] = 0
    heap = [(0, s, -1)]  # distance,source and then color

    from heapq import heappop, heappush
    while len(heap) != 0:
        node = heappop(heap)


def main():
    global n, m, C
    n, m, C = get_ints()
    global graph
    for _ in range(m):
        u, v, w, c = get_ints()
        graph[u].append((w, v, c))
    s, q = get_ints()
    dijkstra(s)


if __name__ == "__main__":
    main()
