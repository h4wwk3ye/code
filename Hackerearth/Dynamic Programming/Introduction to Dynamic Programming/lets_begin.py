# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4Wk3yE
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

inf = float("inf")
mod = 1000000007


import sys
sys.setrecursionlimit(5000000)


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def precompute():
    arr[1] = inf
    for i in range(2, n+1):
        minimum = -1
        for j in primes:
            if j <= i:
                if minimum == -1 or 1+arr[i-j] < minimum:
                    minimum = 1+arr[i-j]
        arr[i] = minimum


def main():
    precompute()
    # print(arr)
    for tc in range(int(input())):
        x = int(input())
        if x < 2:
            print(-1)
        else:
            print(arr[x], sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == "__main__":
    primes = [2, 3, 5, 7]
    n = 10**6
    arr = [0]*(n+1)
    main()
