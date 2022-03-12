# !/usr/bin/env python3
# encoding: utf-8 -*-


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

# https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/number-of-rs-1/
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


def convert(x):
    if x == 'R':
        return 1
    return 0


def main():
    for tc in range(int(input())):
        s = list(map(convert, input().rstrip()))
        n = len(s)
        initial = 0
        b = [0] * n
        for i in range(n):
            if s[i] == 1:
                initial += 1
                b[i] = -1
            else:
                b[i] = 1
        curr_mx, mx = b[0], b[0]
        for i in range(1, n):
            curr_mx = max(b[i], curr_mx + b[i])
            mx = max(curr_mx, mx)
        print(mx + initial)


if __name__ == "__main__":
    main()
