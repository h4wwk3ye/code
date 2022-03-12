#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <07/Feb/2019 06:41:14 PM>


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
'''import resource
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))'''


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()


# ///==========MAIN=============///
stack = []


def explore(graph, node, visited):
    global stack
    visited[node] = True
    for neighbour in graph[node]:
        if visited[neighbour] == False:
            explore(neighbour)
    stack.append(node)


def dfs(graph, n, k):
    visited = [False] * (n + 1)
    for i in range(1, n + 1):
        if visited[i] == False:
            explore(graph, i, visited)


def explore_other(graph, node, visited_other):
    visited_other[node] = True
    for neighbour in graph[node]:
        if visited_other[neighbour] == False:
            explore_other(neighbour)


def dfs_o(graph, n, k):
    global stack
    scc = 0
    visited_other = [False] * (n + 1)
    for node in reversed(stack):
        if visited_other[node] == False:
            scc += 1
            if scc > k:
                return scc
            explore_other(graph, node, visited_other)
    return scc


def npr(n, r):
    ans = 1
    for i in range(r):
        ans *= n
        n -= 1
        ans %= mod
    return ans


def main():
    for tc in range(int(input())):
        k, n, m = get_ints()
        graph = [[] for _ in range(n + 1)]
        graph_reverse = [[] for _ in range(n + 1)]
        for i in range(m):
            u, v = get_ints()
            graph[u].append(v)
            graph_reverse[v].append(u)
        global stack
        stack = []
        dfs(graph_reverse, n, k)
        p = dfs_o(graph, n, k)
        if p > k:
            print(-1)
            continue
        print(int(npr(k, p)) % mod)


if __name__ == "__main__":
    main()
