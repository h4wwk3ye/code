#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/327/A
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
    b = [0]*n
    initial = 0
    for i in range(n):
        if arr[i] == 1:
            b[i] = -1
            initial += 1
        else:
            b[i] = 1
    mx, curr_mx = b[0], b[0]
    for i in range(1, n):
        curr_mx = max(b[i], curr_mx+b[i])
        mx = max(curr_mx, mx)
    print(mx+initial)


if __name__ == "__main__":
    main()
