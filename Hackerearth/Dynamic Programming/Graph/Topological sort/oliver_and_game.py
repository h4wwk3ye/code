#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Feb/2019 06:52:56 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


graph = [[] for i in range(100005)]
visited = [False] * 100005
global time
time = 0
pre = [0] * 100005
post = [0] * 100005


def dfs(node):
    global time
    visited[node] = True
    pre[node] = time
    time += 1
    for neighbour in graph[node]:
        if visited[neighbour] == False:
            dfs(neighbour)
    post[node] = time
    time += 1


def main():
    n = int(input())
    for i in range(n - 1):
        u, v = get_ints()
        graph[u].append(v)
    dfs(1)
    for tc in range(int(input())):
        t, u, v = get_ints()
        if t == 0:
            print('YES' if pre[u] < pre[v] and post[u] > post[v] else 'NO')
        else:
            print('YES' if pre[u] > pre[v] and post[u] < post[v] else 'NO')


if __name__ == "__main__":
    main()
