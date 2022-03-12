#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <05/Feb/2019 09:49:10 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/optimal-connectivity-c6ae79ca/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


graph = {i + 1: [] for i in range(100005)}


def main():
    n = int(input())
    for i in range(n - 1):
        u, v, w = get_ints()
        graph[u].append((w, v))
        graph[v].append((w, u))
    for tc in range(int(input())):
        u, v, w = get_ints()
        flag = 0
        for weight, neighbours in graph[u]:
            print(u, weight)
            if w < weight:
                print('YES')
                flag = 1
                break
        if flag == 1:
            continue
        for weight, neighbours in graph[v]:
            if w < weight:
                print('YES')
                flag = 1
                break
        if flag == 0:
            print('NO')


if __name__ == "__main__":
    main()
