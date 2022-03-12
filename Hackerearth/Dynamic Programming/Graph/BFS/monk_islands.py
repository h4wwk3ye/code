#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <01/Jan/2019 09:40:49 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
#

# ///==========Libraries, Constants and Functions=============///


import sys
from atexit import register
from io import StringIO as stream

inf = float("inf")
mod = 1000000007
#sys.stdin = open('input.txt', 'r')


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    from collections import defaultdict, deque
    for tc in range(int(input())):
        n, m = get_ints()
        Graph = defaultdict(list)
        for i in range(m):
            x, y = get_ints()
            Graph[x].append(y)
            Graph[y].append(x)
        depth = [0] * (n + 1)
        visited = [False] * (n + 1)
        queue = deque()
        queue.append(1)
        depth[1] = 0
        visited[1] = True
        flag = 0
        while queue:
            node = queue.popleft()
            for neighbour in Graph[node]:
                if visited[neighbour] == False:
                    depth[neighbour] = 1 + depth[node]
                    queue.append(neighbour)
                    visited[neighbour] = True
                    if neighbour == n:
                        print(depth[neighbour])
                        flag = 1
                        break
            if flag == 1:
                break


if __name__ == "__main__":
    # fast_io()
    main()
