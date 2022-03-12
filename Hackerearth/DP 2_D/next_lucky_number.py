#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <18/May/2019 12:25:12 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


inf = float('inf')


def solve(i, n):
    x = int(''.join(y for y in n))

    if x in d:
        return d[x]
    if i == l:
        return x if x > o else inf

    p = n.copy()
    q = n.copy()
    p[i] = '3'
    q[i] = '5'
    d[x] = min(solve(i + 1, p), solve(i + 1, q))
    return d[x]


for tc in range(int(input())):
    d = {}
    arr = list(input())
    o = int(''.join(x for x in arr))
    l = len(arr)
    ans = solve(0, arr)
    if ans == inf:
        print('3' * (l + 1))
    else:
        print(ans)
