#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <06/Feb/2019 07:48:18 PM>


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


graph = [[] for _ in range(405)]
graph_reverse = [[] for _ in range(405)]
visited = [False] * 405
visited_other = [False] * 405
stack = []
scc = 0


def explore(node):
    visited[node] = True
    for neighbour in graph_reverse[node]:
        if visited[neighbour] == False:
            explore(neighbour)
    stack.append(node)


def dfs(n, m):
    for i in range(n):
        for j in range(1, m + 1):
            if visited[i * m + j] == False:
                explore(i * m + j)


def explore_other(node):
    visited_other[node] = True
    for neighbour in graph[node]:
        if visited_other[neighbour] == False:
            explore_other(neighbour)


def dfs_o(n, m):
    global scc
    for node in reversed(stack):
        if visited_other[node] == False:
            scc += 1
            #print(node, scc)
            explore_other(node)


def main():
    n, m = get_ints()
    horizontal = input().strip()
    for i in range(n):
        if horizontal[i] == '<':
            for j in range(1, m):
                graph[i * m + j + 1].append(i * m + j)
                graph_reverse[i * m + j].append(i * m + j + 1)
        else:
            for j in range(1, m):
                graph[(i) * m + j].append(i * m + (j + 1))
                graph_reverse[i * m + (j + 1)].append((i) * m + j)
    vertical = input().strip()
    for j in range(1, m + 1):
        if vertical[j - 1] == '^':
            for i in range(n - 1):
                graph[(i + 1) * m + j].append((i) * m + (j))
                graph_reverse[(i) * m + (j)].append((i + 1) * m + j)
        else:
            for i in range(n - 1):
                graph[i * m + j].append((i + 1) * m + (j))
                graph_reverse[(i + 1) * m + (j)].append((i) * m + j)
    '''for i in range(n + 1):
        for j in range(1, m + 1):
            print(graph[i * m + j], end=' ')
        print()
    print('next')
    for i in range(n + 1):
        for j in range(1, m + 1):
            print(graph_reverse[i * m + j], end=' ')
        print()'''

    dfs(n, m)
    # print(stack)
    dfs_o(n, m)
    print('YES' if scc == 1 else 'NO')


if __name__ == "__main__":
    main()
