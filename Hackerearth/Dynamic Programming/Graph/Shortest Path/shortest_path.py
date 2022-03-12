#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <10/Jan/2019 06:24:36 PM>


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

#sys.stdin = open('input.txt', 'r')


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def dijkstra(graph):
    dist = [inf] * 10005
    visited = [False] * 10005
    from heapq import heappop, heappush
    heap = [(0, 1)]
    dist[1] = 0
    while len(heap) != 0:
        cost, node = heappop(heap)
        if visited[node] == True:
            continue
        visited[node] = True
        for weight, neighbour in graph[node]:
            if dist[neighbour] > dist[node] + weight:
                dist[neighbour] = dist[node] + weight
                heappush(heap, (dist[neighbour], neighbour))
    return dist


def main():
    n, m = get_ints()
    graph = {i + 1: [] for i in range(n)}
    for i in range(999200):
        try:
            a, b, w = get_ints()
        except:
            print(i)
            exit()
        graph[a].append((w, b))
        #graph[b].append((w, a))
    distance = dijkstra(graph)
    print(*distance[2:n + 1])


if __name__ == "__main__":
    main()
