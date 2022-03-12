#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <05/Jan/2019 05:21:41 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#   https://www.codechef.com/JAN19A/problems/DPAIRS
#

# ///==========Libraries, Constants and Functions=============///


import sys
#from atexit import register
#from io import StringIO as stream

inf = float("inf")
mod = 1000000007


def fast_io():
    sys.stdin = stream(sys.stdin.read())
    sys.stdout = stream()
    register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def solve(A, B, n, m, ans):
    A = list(enumerate(A))
    B = list(enumerate(B))
    # print(A)
    import operator
    A.sort(key=operator.itemgetter(1))
    B.sort(key=operator.itemgetter(1))
    for i in range(m):
        ans.append((A[0][0], B[i][0]))

    for i in range(1, n):
        ans.append((A[i][0], B[-1][0]))


def main():
    n, m = get_ints()
    A = get_array()
    B = get_array()
    ans = []
    solve(A, B, n, m, ans)
    for i in range(n + m - 1):
        print(*ans[i])


if __name__ == "__main__":
    # fast_io()
    main()
