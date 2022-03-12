# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4Wk3yE
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

inf = float("inf")
mod = 1000000007


import sys


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        n, k = map(int, input().split())
        heights = get_array()
        curr_max, maximum = 0, 0
        i = 0
        while i < n:
            if heights[i] <= k:
                curr_max += heights[i]
            else:
                curr_max = 0
            maximum = max(maximum, curr_max)
            i += 1
        print(maximum)


if __name__ == "__main__":
    main()
