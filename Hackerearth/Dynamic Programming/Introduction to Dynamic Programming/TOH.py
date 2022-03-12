# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior


import sys

inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def solve(disks, n):
    ans = [disks[i][1] for i in range(n)]
    for j in range(1, n):
        for i in range(j):
            if disks[i][0] < disks[j][0] and disks[i][1] < disks[j][1]:
                ans[j] = max(ans[j], ans[i]+disks[j][1])
    return max(ans)


def main():
    for tc in range(int(input())):
        n = int(input())
        disks = [None]*n
        for i in range(n):
            a = get_array()
            disks[i] = a
        #print(disks, sep=' ', end='\n', file=sys.stdout, flush=False)
        disks.sort()
        print(solve(disks, n))


if __name__ == "__main__":
    main()
