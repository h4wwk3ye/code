#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <16/Jan/2019 06:26:42 PM>


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
#sys.stdin = open('inp.txt', 'r')


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n, m, k, x = get_ints()
    cities = get_array()

    graph = {i + 1: [] for i in range(n)}
    for i in range(m):
        u, v, d = get_ints()
        graph[u].append((d, v))
        graph[v].append((d, u))

    def dijkstra(s, distance):
        from heapq import heappop, heappush
        heap = [(0, s)]
        distance[s] = 0
        visited = [False] * (n + 1)
        while len(heap) != 0:
            weight, node = heappop(heap)
            if visited[node] == True:
                continue
            visited[node] = True
            for cost, neighbour in graph[node]:
                if distance[neighbour] > cost + distance[node]:
                    distance[neighbour] = cost + distance[node]
                    heappush(heap, (distance[neighbour], neighbour))

    s, d = get_ints()
    distance = [inf] * (n + 1)
    dijkstra(s, distance)
    other_distance = [inf] * (n + 1)
    dijkstra(d, other_distance)

    min_distance = inf
    for i in range(k):
        if other_distance[cities[i]] <= x:
            min_distance = min(min_distance, distance[cities[i]] + other_distance[cities[i]])

    print(min_distance if min_distance != inf else -1)


if __name__ == "__main__":
    main()
