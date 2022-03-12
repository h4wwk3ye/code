#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/368/B
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
    n, m = get_ints()
    arr = get_array()
    d = {}
    d[arr[-1]] = 1
    ans = [1]*n
    for i in range(n-2, -1, -1):
        x = arr[i]
        if x not in d:
            d[x] = 1
            ans[i] = 1+ans[i+1]
        else:
            ans[i] = ans[i+1]
    # print(ans)
    for i in range(m):
        print(ans[int(input())-1])


if __name__ == "__main__":
    main()
