#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Feb/2019 01:19:28 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(10**6)
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


visited = [False] * 2005
dist = [1] * 2005
graph = [[] for i in range(2005)]
root = []


def explore(node):
    visited[node] = True
    for child in graph[node]:
        if visited[child] == False:
            dist[child] = 1 + dist[node]
            explore(child)


def dfs(n):
    for i in root:
        if visited[i] == False:
            explore(i)


def main():
    n = int(input())
    for i in range(1, n + 1):
        x = int(input())
        if x != -1:
            graph[x].append(i)
        else:
            root.append(i)
    dfs(n)
    print(max(dist[1:n + 1]))


if __name__ == "__main__":
    main()
