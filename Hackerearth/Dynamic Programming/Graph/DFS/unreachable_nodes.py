#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <02/Jan/2019 07:54:28 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream

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


def dfs(graph, root, n):
    stack = []
    count = 1
    visited = [False for _ in range(n + 1)]
    stack.append(root)
    visited[root] = True
    while len(stack) != 0:
        node = stack.pop()
        for neighbour in graph[node]:
            if visited[neighbour] == False:
                stack.append(neighbour)
                visited[neighbour] = True
                count += 1
    return n - count


def main():
    n, m = get_ints()
    graph = {i + 1: [] for i in range(n)}
    for i in range(m):
        a, b = get_ints()
        graph[a].append(b)
        graph[b].append(a)
    root = int(input())
    print(dfs(graph, root, n))


if __name__ == "__main__":
        # fast_io()
    main()
