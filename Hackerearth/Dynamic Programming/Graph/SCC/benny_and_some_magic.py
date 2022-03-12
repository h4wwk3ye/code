#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <23/Jan/2019 07:12:52 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/benny-and-some-magic/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


graph = {i: [] for i in range(1, 300005)}
visited = [False] * 300005
global mx, curr_mx, mn
mx = -1


def explore(node):
    global mx, curr_mx, mn
    visited[node] = True
    for neighbour, weight in graph[node]:
        if visited[neighbour] == False:
            curr_mx = max(curr_mx, weight)
            mn = min(mn, weight)
            mx = max(mx, curr_mx - mn)
            print(curr_mx, mn, mx, node, neighbour)
            explore(neighbour)


def dfs(n):
    for node in range(1, n + 1):
        global mx, curr_mx, mn
        curr_mx, mn = -1, inf
        if visited[node] == False:
            explore(node)


def main():
    n, m = get_ints()
    for i in range(m):
        u, v, w = get_ints()
        graph[u].append((v, w))
        # graph_r[v].append(u)

    dfs(n)
    print(mx)


if __name__ == "__main__":
    main()
