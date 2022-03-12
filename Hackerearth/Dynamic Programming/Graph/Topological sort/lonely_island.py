#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <02/Feb/2019 05:56:34 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
#

# ///==========Libraries, Constants and Functions=============///


import sys
#sys.stdin = open('input_1.txt', 'r')
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


graph = [[] for i in range(2 * (10**5) + 5)]
indegree = [0] * (2 * (10**5) + 5)
outdegree = [0] * (2 * (10**5) + 5)
visited = [False] * (2 * (10**5) + 5)
ways = [0] * (2 * (10**5) + 5)
limit = 1e-9


def topological_sort(n, root):
    from collections import deque
    queue = deque()
    for i in range(1, n + 1):
        if indegree[i] == 0:
            queue.append(i)
    ways[root] = 1
    while len(queue) != 0:
        node = queue.popleft()
        for neighbour in graph[node]:
            ways[neighbour] += ways[node] / outdegree[node]
            indegree[neighbour] -= 1
            if indegree[neighbour] == 0:
                queue.append(neighbour)


def main():
    n, m, r = get_ints()
    count = {}
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        indegree[v] += 1
        outdegree[u] += 1
    topological_sort(n, r)
    mx = -1
    for i in range(1, n + 1):
        if outdegree[i] == 0:
            mx = max(mx, ways[i])
    ans = []
    for i in range(1, n + 1):
        if outdegree[i] == 0 and abs(ways[i] - mx) <= limit:
            ans.append(i)
    print(*ans)


if __name__ == "__main__":
    main()
