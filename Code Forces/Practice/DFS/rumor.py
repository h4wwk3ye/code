#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <03/Feb/2019 02:25:19 PM>


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


scc = 0
graph = [[] for i in range(10**5 + 5)]
visited = [False] * (10**5 + 5)
component = [-1] * (10**5 + 5)


def explore(node):
    visited[node] = True
    component[node] = scc
    for neighbour in graph[node]:
        if visited[neighbour] == False:
            explore(neighbour)


def dfs(n):
    global scc
    for i in range(1, n + 1):
        if visited[i] == False:
            scc += 1
            explore(i)


def main():
    n, m = get_ints()
    gold = get_array()
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    dfs(n)
    from collections import defaultdict
    ans = defaultdict(list)
    for i in range(1, n + 1):
        x = component[i]
        ans[x].append(gold[i - 1])
    u = 0
    print(ans)
    for i in ans:
        u += min(ans[i])
    print(u)


if __name__ == "__main__":
    main()
