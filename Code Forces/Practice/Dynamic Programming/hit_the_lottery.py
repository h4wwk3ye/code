#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/996/A
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()


def print(x): return sys.stdout.write(str(x)+"\n")
# ///==========MAIN=============///


def main():
    n = int(input())
    count = 0
    arr = [1, 5, 10, 20, 100]
    if n >= 100:  # greedy because each coin is a divisor of next coin
        count += (n//100)
        n %= 100
    if n >= 20:
        count += (n//20)
        n %= 20
    if n >= 10:
        count += (n//10)
        n %= 10
    if n >= 5:
        count += (n//5)
        n %= 5
    if n >= 1:
        count += n
    print(count)


if __name__ == "__main__":
    main()
