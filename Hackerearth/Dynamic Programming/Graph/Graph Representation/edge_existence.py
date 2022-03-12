#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Dec/2018 10:47:06 PM>


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


def main():
    from collections import defaultdict
    Graph = defaultdict(list)
    n, m = get_ints()
    for i in range(m):
        a, b = get_ints()
        Graph[a].append(b)
        Graph[b].append(a)
    for q in range(int(input())):
        a, b = get_ints()
        if b in Graph[a]:
            print('YES')
        else:
            print('NO')


if __name__ == "__main__":
    main()
