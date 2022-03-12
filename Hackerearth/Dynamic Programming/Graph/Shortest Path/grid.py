#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <14/Jan/2019 08:02:32 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n, m, q = get_ints()
    matrix = [0] * n
    for i in range(n):
        matrix[i] = input().strip()
    print(matrix)
    si, sj = get_ints()
    si -= 1
    sj -= 1
    queries = [0] * q
    for i in range(q):
        u, v = get_ints()
        queries[i] = [u, v]
    if matrix[si][sj] == '*':
        for i in range(q):
            print(-1)
        return


if __name__ == "__main__":
    main()
