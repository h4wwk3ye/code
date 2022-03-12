#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <02/Jan/2019 02:18:42 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
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


def solve(Graph, u, l, n):
    count = 0
    depth = [0 for _ in range(n + 1)]
    visited = [False for _ in range(n + 1)]
    depth[u] = 0
    visited[u] = True
    from collections import deque
    queue = deque()
    queue.append(u)
    while len(queue) != 0:
        node = queue.popleft()
        for neighbour in Graph[node]:
            if visited[neighbour] == False:
                visited[neighbour] = True
                queue.append(neighbour)
                depth[neighbour] = 1 + depth[node]
                if depth[neighbour] == l:
                    count += 1
                # elif depth[neighbour] > l:
                    # return count
    return count


def main():
    n, e = get_ints()
    Graph = {i: [] for i in range(n + 1)}
    for i in range(e):
        u, v = get_ints()
        Graph[u].append(v)
        Graph[v].append(u)
    m = int(input())
    for i in range(m):
        u, l = get_ints()
        print(solve(Graph, u, l, n))


if __name__ == "__main__":
        # fast_io()
    main()
