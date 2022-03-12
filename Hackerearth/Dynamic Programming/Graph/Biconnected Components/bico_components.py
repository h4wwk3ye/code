#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <21/Jan/2019 08:25:28 PM>


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
global count, even, odd
odd, even = 0, 0


def explore(graph, visited, node, parent, low, disc, time, stack):
    global even, odd
    visited[node] = True
    low[node] = disc[node] = time
    children = 0
    count = 0
    for child in graph[node]:
        if visited[child] == False:
            parent[child] = node
            children += 1
            stack.append((node, child))
            explore(graph, visited, child, parent, low, disc, time + 1, stack)

            if parent[node] == -1 and children > 1:
                while len(stack) > 0 and stack[-1] != (node, child):
                    count += 1
                    stack.pop()
                stack.pop()
                #count += 1
                if count % 2 == 0:
                    even += 1
                else:
                    odd += 1
            elif parent[node] != -1 and low[child] >= disc[node]:
                while len(stack) > 0 and stack[-1] != (node, child):
                    count += 1
                    stack.pop()
                stack.pop()
                #count += 1
                if count % 2 == 0:
                    even += 1
                else:
                    odd += 1
        elif parent[node] != child and low[node] > disc[child]:
            low[node] = min(low[node], disc[child])
            stack.append((node, child))


def dfs(graph, n, m):
    visited = [False] * (n + 1)
    parent = [-1] * (n + 1)
    low = [inf] * (n + 1)
    disc = [-1] * (n + 1)

    for i in range(n):
        if visited[i] == False:
            stack = []
            global even, odd
            count = 0
            explore(graph, visited, i, parent, low, disc, 0, stack)
            while len(stack) != 0:
                count += 1
                stack.pop()
            if count != 0:
                if count % 2 == 0:
                    even += 1
                else:
                    odd += 1

    return odd, even


def main():
    n, m = get_ints()
    graph = {i: [] for i in range(n)}
    for i in range(m):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    print(*dfs(graph, n, m))


if __name__ == "__main__":
    main()
