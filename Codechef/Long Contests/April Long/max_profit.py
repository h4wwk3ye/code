#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <07/Apr/2019 06:16:12 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior


# ///==========Libraries, Constants and Functions=============///


import sys
#import resource
sys.setrecursionlimit(10**6)
#resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def dfs(node, parent):
    for to in graph[node]:
        if to == parent:
            continue
        children[node].append(to)
        dfs(to, node)


def dfs_another(node,):
    return max(-x, arr[node-1] + sum(map(dfs_another, children[node])))


def main():
    for tc in range(int(input())):
        global x, arr, graph, children
        n, x = get_ints()
        arr = get_array()
        graph = [[] for _ in range(n+1)]
        children = [[] for _ in range(n+1)]
        for i in range(n-1):
            u, v = get_ints()
            graph[u].append(v)
            graph[v].append(u)
        dfs(1, 1)
        print(dfs_another(1))


if __name__ == "__main__":
    main()
