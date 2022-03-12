#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Jan/2019 10:49:43 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
sys.setrecursionlimit(1000000000)
#from atexit import register
#from io import StringIO as stream

inf = float("inf")
mod = 1000000007


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def dfs(node, w):
    if s[node] == -1:
        s[node] = w
        if len(graph[node]) != 0:
            for vertex in graph[node]:
                if s[vertex] < w:
                    print(-1)
                    sys.exit()
            s[node] = s[graph[node][0]]
            for vertex in graph[node]:
                s[node] = min(s[node], s[vertex])
    if s[node] < w:
        print(-1)
        sys.exit()
    w = s[node]
    global ans
    ans += (s[node] - s[parent[node]])
    for vertex in graph[node]:
        dfs(vertex, w)


if __name__ == "__main__":
        # fast_io()
    n = int(input())
    graph = {i + 1: [] for i in range(n)}
    x = get_array()
    parent = [0] * (n + 1)
    for i in range(n - 1):
        graph[x[i]].append(i + 2)
        parent[i + 2] = x[i]
    s = get_array()
    s.insert(0, 0)
    global ans
    ans = 0
    dfs(1, 0)
    print(ans)
