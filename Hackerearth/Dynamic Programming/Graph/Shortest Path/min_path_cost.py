#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <15/Jan/2019 06:58:38 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/minimizing-path-cost/
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
    n, m = get_ints()
    stations = list(input().split())
    d = {}
    for i in range(n):
        d[stations[i]] = i + 1
    graph = {i + 1: [] for i in range(n)}

    distance = [[inf] * (n + 1) for _ in range(n + 1)]

    for i in range(m):
        u, v, c = input().split()
        c = int(c)
        u = d[u]
        v = d[v]
        distance[u][v] = c
        distance[v][u] = c

    for i in range(n + 1):
        distance[i][i] = 0

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if distance[i][j] > distance[i][k] + distance[k][j]:
                    distance[i][j] = distance[i][k] + distance[k][j]

    for tc in range(int(input())):
        u, v = input().split()
        u = d[u]
        v = d[v]
        print(distance[u][v])


if __name__ == "__main__":
    main()
