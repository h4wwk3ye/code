#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://www.hackerearth.com/challenge/competitive/december-circuits-18/algorithm/picking-the-coins-50470dca/
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
    for tc in range(int(input())):
        n, k = get_ints()
        flag = 1
        i = 1
        if k == 1:
            n %= 2
            if n == 0:
                print('Bob')
            else:
                print('Alice')
        else:
            while n >= pow(k, i):
                flag = 1-flag
                n -= pow(k, i)
                if flag == 1:
                    i += 1
            if flag == 0:
                print('Alice')
            else:
                print('Bob')


if __name__ == "__main__":
    main()
