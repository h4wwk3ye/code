#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/433/B
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    n = int(input())
    arr = get_array()
    other = sorted(arr)
    prefix_sum = [0]*(n+1)
    other_sum = [0]*(n+1)
    for i in range(1, n+1):
        prefix_sum[i] = prefix_sum[i-1]+arr[i-1]
        other_sum[i] = other_sum[i-1]+other[i-1]
    for tc in range(int(input())):
        t, l, r = get_ints()
        if t == 1:
            print(prefix_sum[r]-prefix_sum[l-1])
        else:
            print(other_sum[r]-other_sum[l-1])


if __name__ == "__main__":
    main()
