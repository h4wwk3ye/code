#	!/bin/env python3
#	encoding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/contest/1095/problem/C
#

# ///==========Libraries, Constants and Functions=============///


import sys
import math
inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def highestPowerof2(n):

    p = int(math.log(n, 2))
    return int(pow(2, p))


def main():
    n, k = get_ints()
    if k > n:
        print('NO')
        return
    if k == n:
        print('YES')
        for i in range(n):
            print(1, end=' ')
        print()
        return
    powers = []
    while n > 0:
        powers.append(highestPowerof2(n))
        n -= powers[-1]



if __name__ == "__main__":
    main()
