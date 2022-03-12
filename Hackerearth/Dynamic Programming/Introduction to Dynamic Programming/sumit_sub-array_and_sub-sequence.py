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


def get_ints():
    return map(int, input().split())

# ///==========MAIN=============///


def sub_array(arr):
    curr_max = arr[0]
    mx = arr[0]
    for i in range(1, len(arr)):
        if curr_max < 0:
            curr_max = max(curr_max, arr[i])
            mx = max(curr_max, mx)
        elif arr[i]+curr_max >= 0:
            curr_max += arr[i]
            mx = max(mx, curr_max)
        else:
            curr_max = arr[i]
    return mx


def sub_sequence(arr):
    total = arr[0]
    for i in range(1, len(arr)):
        if total < 0:
            total = max(total, arr[i])
        elif arr[i] > 0:
            total += arr[i]

    return total


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        x = sub_array(arr)
        y = sub_sequence(arr)
        print(x, y)


if __name__ == "__main__":
    main()
