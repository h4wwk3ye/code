#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <14/Jan/2019 08:33:30 PM>


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


def main():
    k = int(input())
    n = int(input())
    x = int(input())

    graph = {i + 1: [] for i in range(n)}
    for i in range(x):
        u, v, t, c = get_ints()
        t += 1  # layover time
        graph[u].append((t * k + c, v, t))
        graph[v].append((t * k + c, u, t))
    print(graph)
    s = int(input())
    d = int(input())

    def dijkstra(s):
        from heapq import heappop, heappush
        heap = [(0, s)]
        visited = [False] * (n + 1)
        distance[s] = 0
        while heap:
            weight, node = heappop(heap)
            if visited[node] == True:
                continue
            visited[node] = True
            for cost, neighbour, time in graph[node]:
                if distance[neighbour] > cost + distance[node]:
                    prev[neighbour] = node
                    distance[neighbour] = cost + distance[node]
                    heappush(heap, (distance[neighbour], neighbour))

    distance = [inf] * (n + 1)
    prev = [-1] * (n + 1)
    dijkstra(s)
    print(prev)
    print(distance)
    print(distance[d])


if __name__ == "__main__":
    main()
