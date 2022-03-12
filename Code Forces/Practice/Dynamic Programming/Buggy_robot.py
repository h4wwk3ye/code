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
    n = int(input())
    com = input().rstrip()
    aux = [0]*4   # 0-L, 1-R, 2-U, 3-D
    for i in com:
        if i == 'L':
            aux[0] += 1
        elif i == 'R':
            aux[1] += 1
        elif i == 'U':
            aux[2] += 1
        else:
            aux[3] += 1
    sideway = min(aux[0], aux[1])*2
    vertical = min(aux[2], aux[3])*2
    print(sideway+vertical)


if __name__ == "__main__":
    main()
