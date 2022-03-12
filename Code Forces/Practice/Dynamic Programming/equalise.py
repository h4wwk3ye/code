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
    cost = 0
    str_a = list(input().strip())
    str_b = list(input().strip())
    for i in range(len(str_a)-1):
        if str_a[i] == str_b[i]:
            continue
        elif str_a[i] == str_b[i+1] and str_b[i] == str_a[i+1]:
            str_b[i] = str(1-int(str_b[i]))
            str_b[i+1] = str(1-int(str_b[i+1]))
            cost += 1
        else:
            str_b[i] = str(1-int(str_b[i]))
            cost += 1
    if str_a[-1] != str_b[-1]:
        cost += 1
    print(cost)


if __name__ == "__main__":
    main()
