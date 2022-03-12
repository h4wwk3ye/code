#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-two-arrays/
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
    n, q = get_ints()
    A = get_array()
    B = get_array()
    odd_A = [0]*(n+1)
    odd_B = [0]*(n+1)
    even_A = [0]*(n+1)
    even_B = [0]*(n+1)
    for i in range(1, n+1):
        if i % 2 == 1:
            odd_A[i] = odd_A[i-1]+A[i-1]
            odd_B[i] = odd_B[i-1]+B[i-1]

            even_A[i] = even_A[i-1]
            even_B[i] = even_B[i-1]
        else:
            odd_A[i] = odd_A[i-1]
            odd_B[i] = odd_B[i-1]

            even_A[i] = even_A[i-1]+A[i-1]
            even_B[i] = even_B[i-1]+B[i-1]

    for i in range(q):
        t, l, r = get_ints()
        if t == 1:
            if l % 2 == 0:
                x = even_A[r]-even_A[l-1]
                y = odd_B[r]-odd_B[l-1]
                print(x+y)
            else:
                x = odd_A[r]-odd_A[l-1]
                y = even_B[r]-even_B[l-1]
                print(x+y)
        else:
            if l % 2 == 0:
                x = odd_A[r]-odd_A[l-1]
                y = even_B[r]-even_B[l-1]
                print(x+y)
            else:
                x = even_A[r]-even_A[l-1]
                y = odd_B[r]-odd_B[l-1]
                print(x+y)


if __name__ == "__main__":
    main()
