#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/bike-trip/
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


if __name__ == "__main__":
    for tc in range(int(input())):
        n = int(input())
        first = get_array()
        second = get_array()
        if n == 1:
            print(min(first[0], second[0]))
            continue
        f_s = get_array()
        s_f = get_array()
        dp1 = [inf]*(n)
        dp2 = [inf]*n
        dp1[0] = first[0]
        dp2[0] = second[0]
        for i in range(1, n):
            dp1[i] = min(dp1[i-1]+first[i], dp2[i-1]+s_f[i-1]+first[i])
            dp2[i] = min(dp2[i-1]+second[i], dp1[i-1]+f_s[i-1]+second[i])
        print(min(dp1[-1], dp2[-1]))
