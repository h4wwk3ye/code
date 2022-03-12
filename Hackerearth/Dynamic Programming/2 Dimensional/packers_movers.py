# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

'''
https://www.hackerearth.com/practice/
algorithms/dynamic-programming/2-dimensional/practice-problems/
algorithm/packers-n-movers/editorial/
'''
import sys

inf = float("inf")
mod = 1000000007


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()


def get_ints():
    return map(int, sys.stdin.readline().split())

# ///==========MAIN=============///


def recurse(movers, packs):
    if movers == m:
        if packs == p:
            return 0
        return inf
    if packs == p:
        return 0
    if dp[movers][packs] != -1:
        return dp[movers][packs]
    total = 0
    ans = recurse(movers+1, packs)  # this mover doesnt moves a package
    for i in range(packs, p):
        total += weights[i]
        ans = min(ans, max(total, recurse(movers+1, i+1)))
    dp[movers][packs] = ans
    return ans


if __name__ == "__main__":
    m = int(input())
    p = int(input())
    weights = get_array()
    dp = [[-1 for i in range(p+1)]for j in range(m+1)]
    print(recurse(0, 0))
