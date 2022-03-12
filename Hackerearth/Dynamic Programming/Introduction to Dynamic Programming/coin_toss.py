#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/coin-toss/
#

# ///==========Libraries, Constants and Functions=============///


import sys
import numpy as np
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def tribonacci(n):
    matrix = np.matrix([[1, 1, 1], [1, 0, 0], [0, 1, 0]])
    matrix = ((matrix % mod)**(n-2)) % mod
    return (matrix[0, 0]+matrix[0, 1]) % mod


def main():
    for tc in range(int(input())):
        n = int(input())
        print(tribonacci(n+3))


if __name__ == "__main__":
    main()
