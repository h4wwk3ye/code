#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <02/Jan/2019 08:15:38 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
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


def main():
    n = int(input())
    graph = {1 + i: [] for i in range(n)}
    for i in range(n - 1):
        a, b = get_ints()
        graph[a].append(b)
        graph[b].append(a)
    d = {}
    for i in range(int(input())):
        d[int(input())] = 1
    from collections import deque
    queue = deque()
    queue.append(1)
    visited = [False for _ in range(n + 1)]
    visited[1] = True
    while queue:
        node = queue.popleft()
        for neighbour in graph[node]:
            if visited[neighbour] == False:
                queue.append(neighbour)
                visited[neighbour] = True
                if neighbour in d:
                    print(neighbour)
                    return


if __name__ == "__main__":
        # fast_io()
    main()
