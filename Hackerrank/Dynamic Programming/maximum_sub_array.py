#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerrank.com/challenges/maxsubarray/problem
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def subarray(arr):
    curr_mx, mx = arr[0], arr[0]
    for i in range(1, len(arr)):
        curr_mx = max(arr[i], curr_mx+arr[i])
        mx = max(curr_mx, mx)
    return mx


def subsequence(arr):
    mx = arr[0]
    for i in range(1, len(arr)):
        if mx < 0:
            if arr[i] > mx:
                mx = arr[i]
        else:
            if arr[i] > 0:
                if mx < 0:
                    mx = 0
                mx += arr[i]
    return mx


def main():
    for tc in range(int(input())):
        n = int(input())
        arr = get_array()
        x = subarray(arr)
        y = subsequence(arr)
        print(x, y)


if __name__ == "__main__":
    main()
