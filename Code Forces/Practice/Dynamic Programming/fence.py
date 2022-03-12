#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#
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
    n, k = get_ints()
    arr = get_array()
    prefix_sum = [0]*n
    prefix_sum[0] = arr[0]
    for i in range(1, n):
        prefix_sum[i] = arr[i]+prefix_sum[i-1]
    mx = prefix_sum[k-1]
    index = 0
    for i in range(1, n-k+1):
        if prefix_sum[i+k-1]-prefix_sum[i-1] < mx:
            mx = prefix_sum[i+k-1]-prefix_sum[i-1]
            index = i

    print(index+1, sep=' ', end='\n', file=sys.stdout, flush=False)


if __name__ == "__main__":
    main()
