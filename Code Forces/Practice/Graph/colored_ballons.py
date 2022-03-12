#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <20/Feb/2019 10:58:47 AM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/780/C
#

# ///==========Libraries, Constants and Functions=============///


import sys
import threading
sys.setrecursionlimit(10**6)
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


N = int(2e5+5)
graph = [[] for _ in range(N)]
color = [1]*N
visited = [False]*N


def dfs(node, parent):
    curr = 1
    for neighbour in graph[node]:
        if neighbour != parent:
            while curr == color[node] or curr == color[parent]:
                curr += 1
            color[neighbour] = curr
            curr += 1
            dfs(neighbour, node)


def main():
    global n
    n = int(input())
    for _ in range(n-1):
        u, v = get_ints()
        graph[u].append(v)
        graph[v].append(u)
    ans = -1
    for i in range(1, n+1):
        ans = max(ans, len(graph[i]))
    dfs(1, -1)
    print(ans+1)
    print(*color[1:n+1])


if __name__ == "__main__":
    threading.stack_size(10**8)
    t = threading.Thread(target=main)
    t.start()
    t.join()
