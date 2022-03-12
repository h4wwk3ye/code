#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <18/May/2019 02:42:39 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


#def input(): return sys.stdin.readline().strip()


#import resource
sys.setrecursionlimit(10**6)
#resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))


def solve(i, j, c):
    print(i, j, c)
    if c == k:
        return 0
    if i >= n:
        return 0

    if (i, j, c) in dp:
        return dp[(i, j, c)]
    if j == 0:
        dp[(i, j, c)] = max(solve(i + 1, 0, c), solve(i + 1, 1, c + 1) + arr[i])
    else:
        dp[(i, j, c)] = max(solve(i + p, 0, c), solve(i + p + 1, 0, c + 1) + arr[i])
    return dp[(i, j, c)]


if __name__ == "__main__":
    sys.stdin = open('inp.txt', 'r')
    dp = {}
    n, k, p = get_ints()
    arr = get_array()
    print(solve(0, 0, 0))
