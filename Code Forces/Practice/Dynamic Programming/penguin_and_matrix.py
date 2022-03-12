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
    n, m, d = get_ints()
    mat = []
    for i in range(n):
        mat.extend(get_array())
    check = mat[0] % d
    for i in range(n*m):
        if mat[i] % d != check:
            print(-1)
            return
    mat.sort()
    median = mat[(n*m)//2]
    ans = 0
    for i in range(n*m):
        ans += abs(mat[i]-median)
    print(ans//d)


if __name__ == "__main__":
    main()
