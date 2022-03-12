#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/961/B
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
    awake = get_array()
    prefix_sum = [0]*(n+1)
    ans = 0
    for i in range(1, n+1):
        prefix_sum[i] += prefix_sum[i-1]
        if awake[i-1] == 0:
            prefix_sum[i] += arr[i-1]
        else:
            ans += arr[i-1]
    add = 0
    for i in range(k, n+1):
        x = prefix_sum[i]-prefix_sum[i-k]
        add = max(add, x)
    print(ans+add)


if __name__ == "__main__":
    main()
