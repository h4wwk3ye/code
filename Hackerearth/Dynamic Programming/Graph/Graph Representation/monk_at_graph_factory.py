#	!/bin/env python3
#	encoding: UTF-8
#	Modified: <31/Dec/2018 11:05:43 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/description/
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
    from collections import Counter
    n = int(input())
    arr = get_array()
    if sum(arr) == (2 * n) - 1:
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    main()
