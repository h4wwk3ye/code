#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <14/Jan/2019 03:34:56 PM>


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


def dfs(node, parent, d):
    global graph, c, l
    lf = 1
    for neighbour in graph[node]:
        if neighbour != parent:
            lf = 0
            dfs(neighbour, node, d ^ 1)
    if lf == 1:
        l[d & 1].append(node)
    else:
        c[d & 1].append(node)


def main():
    global graph, c, l
    for tc in range(int(input())):
        n = int(input())
        graph = {i + 1: [] for i in range(n)}
        for i in range(n - 1):
            u, v = get_ints()
            graph[u].append(v)
            graph[v].append(u)
        c, l = [[], []], [[], []]
        dfs(1, 1, 0)
        e = c[0] + l[0]
        o = c[1] + l[1]
        print(1) if len(o) == len(e) else print(2)
        if len(o) > len(e):
            o, e = e, o
        while len(o) < len(e):
            o.append(e.pop())
        print(*o)
        print(*e)


if __name__ == "__main__":
    main()
