#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <23/Jan/2019 06:30:11 PM>


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


graph = {i: [] for i in range(1, 16)}
graph_r = {i: [] for i in range(1, 16)}
visited = [False] * 16
stack = []
visited_other = [False] * 16
global even, odd
odd, even = 0, 0


def explore(node):
    visited[node] = True
    for neighbour in graph_r[node]:
        if visited[neighbour] == False:
            explore(neighbour)
    stack.append(node)


def dfs(n):
    for i in range(1, n + 1):
        if visited[i] == False:
            explore(i)


def explore_other(node):
    global count
    count += 1
    visited_other[node] = True
    for neighbour in graph[node]:
        if visited_other[neighbour] == False:
            explore_other(neighbour)


def dfs_o(n):
    global even, odd
    for node in reversed(stack):
        if visited_other[node] == False:
            global count
            count = 0
            explore_other(node)
            if count % 2 == 0:
                even += count
            else:
                odd += count


def main():
    n, m = get_ints()
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph_r[v].append(u)
    dfs(n)  # dfs on reverse graph

    dfs_o(n)

    print(odd - even)


if __name__ == "__main__":
    main()
