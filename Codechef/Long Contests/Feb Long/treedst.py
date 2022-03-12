#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <01/Feb/2019 10:36:15 PM>


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


graph = [[] for _ in range(10**5 + 5)]
dist = [0] * (10**5 + 5)
visited = [False] * (10**5 + 5)


def bfs():
    dist[1] = 0
    from collections import deque
    queue = deque()
    queue.append(1)
    while len(queue) != 0:
        node = queue.popleft()
        visited[node] = True
        for child in graph[node]:
            if visited[child] == False:
                dist[child] = 1 + dist[node]
                queue.append(child)


def main():
    n = int(input())
    arr_k = get_array()
    for i in range(n - 1):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    bfs()
    from collections import Counter
    count = Counter(dist[1:n + 1])
    print(count)


if __name__ == "__main__":
    main()
