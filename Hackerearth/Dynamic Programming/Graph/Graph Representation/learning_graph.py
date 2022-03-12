#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <05/Feb/2019 09:24:07 PM>


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
graph = [[] for _ in range(1005)]


def main():
    n, m, k = get_ints()
    nodes = get_array()
    for i in range(m):
        u, v = get_ints()
        graph[u].append((nodes[v - 1], v))
        graph[v].append((nodes[u - 1], u))
    '''for i in range(1, n + 1):
        graph[i].sort(reverse=True)'''
    for i in range(1, n + 1):
        if len(graph[i]) < k:
            print(-1)
        else:
            graph[i].sort(reverse=True)
            print(graph[i][k - 1][1])


if __name__ == "__main__":
    main()
