#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <09/Jan/2019 07:34:23 PM>


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


def prims(graph):
    from heapq import heappop, heappush
    heap


def main():
    for tc in range(int(input())):
        n, m, k = get_ints()
        graph = {i + 1: [] for i in range(n)}
        for i in range(m):
            a, b, c = get_ints()
            graph[a].append((w, b))
            graph[b].append((w, a))
        prims(graph)


if __name__ == "__main__":
    main()
