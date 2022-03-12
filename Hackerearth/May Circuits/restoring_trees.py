#	!/usr/bin/env python3
#	encoding: UTF-8
#	Modified: <27/May/2019 10:33:34 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT), Gwalior


import sys


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline().strip()


d = {}
n = int(input())
t = [0] * n
parent = [0] * (n + 1)
pre = get_array()
post = get_array()
for i in range(n):
    t[i] = (pre[i], post[i])
    d[(pre[i], post[i])] = i + 1

t.sort()
for i in range(1, n):
    if t[i][0] > t[i - 1][0] and t[i][1] <= t[i - 1][1]:
        parent[d[(t[i][0], t[i][1])]] = d[(t[i - 1][0], t[i - 1][1])]
    else:
        j = i - 2
        while j >= 0:
            if t[i][0] > t[j][0] and t[i][1] <= t[j][1]:
                parent[d[(t[i][0], t[i][1])]] = d[(t[j][0], t[j][1])]
                break
            else:
                j -= 1
print(*parent[1:n + 1])
